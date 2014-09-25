/*
 * Josh Hursey
 *
 * CS441/541: Project 1 Part 1
 *
 */
#include "mysh.h"

int main(int argc, char * argv[]) {

    if (argc > 1) {
        batch_mode(argc, argv);
    } else if (argc == 1) {
        interactive_mode();
    }

    return 0;
}

void print_line_indicator() {
    printf("mysh$ ");
    fflush(NULL);
}

void clean_jobs(job_t * loc_jobs, int num_jobs) {
    int i, j;
    if( NULL != loc_jobs ) {
        /* Cleanup struct fields */
        for( i = 0; i < num_jobs; ++i ) {
            /* .full_command */
            if( NULL != loc_jobs[i].full_command ) {
                free( loc_jobs[i].full_command );
                loc_jobs[i].full_command = NULL;
            }

            /* .argv */
            if( NULL != loc_jobs[i].argv ) {
                for( j = 0; j < loc_jobs[i].argc; ++j ) {
                    if( NULL != loc_jobs[i].argv[j] ) {
                        free( loc_jobs[i].argv[j] );
                        loc_jobs[i].argv[j] = NULL;
                    }
                }
                free( loc_jobs[i].argv );
                loc_jobs[i].argv = NULL;
            }

            /* .argc */
            loc_jobs[i].argc = 0;
        }

        /* Free the array */
        free(loc_jobs);
    }
}

int interactive_mode() {
    char line[MAX_COMMAND_LINE + 1];
    int num_jobs = 0, last = 0, num_built_in = 0, num_background = 0;
    job_t * loc_jobs = NULL;
    int i, j;
    char *template, symbol = ' ';

    loc_jobs = (job_t*)malloc(sizeof(job_t) * 1);
    if( NULL == loc_jobs ) {
        fprintf(stderr, "Error: Failed to allocate memory! Critical failure on %d!", __LINE__);
        exit(-1);
    }

    print_line_indicator();
    while (fgets(line, MAX_COMMAND_LINE, stdin) != NULL) {
        trim(line, line);
        if (!strcmp("", line)) {
            print_line_indicator();
            continue;
        }

        split_input_into_jobs(line, &num_jobs, &loc_jobs);

        for (i = last; i < num_jobs; ++i) {
            split_job_into_args( &(loc_jobs[i]) );

            template = "Job  %d%c: ";
            if (BACKGROUND == loc_jobs[i].run_type) {
                symbol = '*';
                num_background++;
            }

            if (is_built_in(loc_jobs[i].argv[0])) {
                symbol = 'x';
                num_built_in++;
            }
            printf(template, i + 1, symbol);
            fflush(NULL);
            for( j = 0; j < loc_jobs[i].argc; ++j ) {
                if (0 == j) {
                    printf("\"%s\" ", loc_jobs[i].argv[j]);
                } else {
                    printf(" [%s]", loc_jobs[i].argv[j]);
                    fflush(NULL);
                }
            }
            printf("\n");
            fflush(NULL);
        }
        last = num_jobs;

        print_line_indicator();
    }

    print_statistics(num_jobs - num_built_in, num_jobs, num_background);

    clean_jobs(loc_jobs, num_jobs);
    loc_jobs = NULL;

    return 0;
}

int batch_mode(int argc, char **argv) {
    char line[MAX_COMMAND_LINE + 1];
    int num_jobs = 0, last = 0, num_built_in = 0, num_background = 0;
    job_t * loc_jobs = NULL;
    FILE *fd;
    int i, j;
    char *template, symbol;

    loc_jobs = (job_t*)malloc(sizeof(job_t) * 1);
    if( NULL == loc_jobs ) {
        fprintf(stderr, "Error: Failed to allocate memory! Critical failure on %d!", __LINE__);
        exit(-1);
    }

    for (i = 1; i < argc; i++) {
        fd = fopen(argv[i], "r");
        if (NULL == fd) {
            fprintf(stderr, "Error: Failed to open file %s! Critical failure on %d!", argv[i], __LINE__);
            exit(-1);
        }

        while (fgets(line, MAX_COMMAND_LINE, fd) != NULL) {
            trim(line, line);
            if (!strcmp("", line)) {
                continue;
            }

            split_input_into_jobs(line, &num_jobs, &loc_jobs);

            for (i = last; i < num_jobs; ++i) {
                split_job_into_args( &(loc_jobs[i]) );

                template = "Job  %d%c: ";
                if (BACKGROUND == loc_jobs[i].run_type) {
                    symbol = '*';
                    num_background++;
                }

                if (is_built_in(loc_jobs[i].argv[0])) {
                    symbol = 'x';
                    num_built_in++;
                }
                printf(template, i + 1, symbol);
                fflush(NULL);
                for( j = 0; j < loc_jobs[i].argc; ++j ) {
                    if (0 == j) {
                        printf("\"%s\" ", loc_jobs[i].argv[j]);
                    } else {
                        printf(" [%s]", loc_jobs[i].argv[j]);
                        fflush(NULL);
                    }
                }
                printf("\n");
                fflush(NULL);
            }
            last = num_jobs;
        }

        fclose(fd);
    }

    print_statistics(num_jobs - num_built_in, num_jobs, num_background);

    clean_jobs(loc_jobs, num_jobs);

    return 0;
}

void print_statistics(int num_jobs, int num_history, int num_background) {
    printf("\n-------------------------------\n");
    printf("Total number of jobs               = %d\n", num_jobs);
    printf("Total number of jobs in history    = %d\n", num_history);
    printf("Total number of jobs in background = %d\n", num_background);
}

bool is_built_in(char *command) {
    char buf[MAX_COMMAND_LINE];
    int i;

    trim(command, buf);

    for (i = 0; i < NUM_BUILT_IN; ++i) {
        if (!strcmp(built_ins[i], buf)) {
            return true;
        }
    }

    return false;
}
