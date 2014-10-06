/**
* Author: Sanhu Li, Huifeng Zhang
* Date: Oct. 5, 2014
*/

#include "mysh.h"

int main(int argc, const char *argv[]) {

    jobs = (job_t *) malloc(sizeof(job_t) * BLOCK_SIZE);
    run_types = (run_t *) malloc(sizeof(run_t) * BLOCK_SIZE);
    pids = (int *) malloc(sizeof(int) * BLOCK_SIZE);
    states = (job_s_t *) malloc(sizeof(job_s_t) * BLOCK_SIZE);
    jids = (int *) malloc(sizeof(int) * BLOCK_SIZE);

    if (argc > 1) {
        batch_mode(argc, argv);
    } else {
        inter_mode();
    }

    return 0;
}

void print_indicator() {
    printf("mysh$ ");
    fflush(stdout);
}

bool is_builtin(const char *command) {
    if (!strcmp("exit", command)) {
        return true;
    }

    if (!strcmp("jobs", command)) {
        return true;
    }

    if (!strcmp("history", command)) {
        return true;
    }

    return false;
}

void process_builtin(const char *command) {
    if (!strcmp("exit", command)) {
        my_exit();
    }

    if (!strcmp("jobs", command)) {
        my_jobs();
    }

    if (!strcmp("history", command)) {
        my_history();
    }
}

int process_line(FILE *stream) {
    char line[MAX_LINE], *result;
    int last, i;

    last = num_jobs;
    result = fgets(line, MAX_LINE, stream);

    if (NULL == result) {
        return -1;
    }

    result = trim(line);
    strcpy(line, result);
    free(result);

    if (!strcmp("", line)) {
        return 0;
    }

    split_input_into_jobs(line, &num_jobs, &jobs, &run_types);

    for (i = last; i < num_jobs; ++i) {
        split_job_into_args(&(jobs[i]));

        if (is_builtin(jobs[i].argv[0])) {
            process_builtin(jobs[i].argv[0]);
        } else {
            my_process(jobs[i], run_types[i], i);
        }
    }

    return 0;
}

void my_process(job_t job, run_t run_type, int jid) {
    int pid;

    pids = (int *) realloc(pids, sizeof(int) * BLOCK_SIZE * ((p_num + 1) / BLOCK_SIZE + 1));
    states = (job_s_t *) realloc(states, sizeof(job_s_t) * BLOCK_SIZE * ((p_num + 1) / BLOCK_SIZE + 1));
    jids[p_num] = jid;

    pid = fork();
    if (-1 == pid) {
        fprintf(stderr, "Failed to process job because unable to fork.\n");
        fprintf(stderr, "Job: %s", job.argv[0]);
    } else if (0 == pid) {
        execvp(job.argv[0], job.argv);

        //  This should not be reached if doing well.
        fprintf(stderr, "Error processing job:\n");
        fprintf(stderr, "\t%s\n", job.full_command);
    } else {
        pids[p_num] = pid;
        states[p_num++] = RUNNING;
        if (FORE == run_type) {
            waitpid(pid, NULL, 0);
            states[p_num - 1] = DONE;
        }
    }
}

void inter_mode() {
    print_indicator();
    while (-1 != process_line(stdin)) {
        print_indicator();
    }

    my_exit();
}

void batch_mode(int argc, const char *argv[]) {
    int i;
    FILE *fd;
    for (i = 1; i < argc; ++i) {
        fd = fopen(argv[i], "r");

        if (NULL == fd) {
            fprintf(stderr, "Cannot open file %s\n", argv[i]);
            continue;
        }

        while (-1 != process_line(fd));
        fclose(fd);
    }
    printf("\n");
    my_exit();
}

void my_exit() {
    int num_back = 0, i, count = 0;
    for (i = 0; i < num_jobs; ++i) {
        if (BACK == run_types[i]) {
            num_back++;
        }
    }

    for (i = 0; i < p_num; ++i) {
        if (states[i] == RUNNING) {
            count++;
        }
    }

    if (count > 0) {
        //  printf("\nPlease waiting for %d process(es)...", count);
        printf("\nWaiting on %d jobs to finish running in the background!", count);
        fflush(NULL);

        while (wait(NULL) > 0) ;
    }
  //  printf("\nAll jobs down, exit \n");

    printf("\n-------------------------------\n");
    printf("Total number of jobs               = %d\n", p_num);
    printf("Total number of jobs in history    = %d\n", num_jobs);
    printf("Total number of jobs in background = %d\n", num_back);



//    for (i = 0; i < num_jobs; ++i) {
//        for (j = 0; j < jobs[i].argc; ++j) {
//            safe_free(&(jobs[i].argv[j]));
//        }
//        safe_free(&(jobs[i].full_command));
//    }
//    free(jobs);
//    free(run_types);
//    free(pids);
//    free(states);
//    free(jids);
    exit(0);
}

void my_jobs() {
    int i, j;
    char *template = "[%d]\t%s\t%s\n";

    //  Before we print out the states, first check all children
    for (i = 0; i < p_num; ++i) {
        if (states[i] != SHOWN) {
            j = waitpid(pids[i], NULL, WNOHANG);
            if (0 == j) {
                states[i] = RUNNING;
            } else if (j > 0 || -1 == j) {
                states[i] = DONE;
            }
        }
    }

    for (i = 0; i < p_num; ++i) {
        if (states[i] != SHOWN) {
            printf(template, i + 1, RUNNING == states[i] ? "Running" : "Done", jobs[jids[i]].full_command);
            if (DONE == states[i]) {
                states[i] = SHOWN;
            }
        }
    }
}

void my_history() {
    int i;
    char *template = "%4d\t%s %c\n";

    for (i = 0; i < num_jobs; ++i) {
        printf(template, i + 1, jobs[i].full_command, BACK == run_types[i] ? '&' : ' ');
    }
}
