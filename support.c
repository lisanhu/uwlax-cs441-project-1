#include "support.h"

char *trim(const char *src) {
    int length = strlen(src), i;
    char *result = (char *) malloc((length + 1) * sizeof(char));

    for (i = 0; i < length; ++i) {
        if (!isspace(src[i])) {
            break;
        }
    }

    strcpy(result, src + i);
    length = strlen(result);

    for (i = length - 1; i >= 0 ; --i) {
        if (isspace(result[i])) {
            result[i] = '\0';
        } else {
            break;
        }
    }

    return result;
}

int split_input_into_jobs(char *input_str, int *num_jobs, job_t **p_jobs, run_t **p_rtypes)
{
    char * str_ptr  = NULL;
    char command[MAX_COMMAND_LINE];
    int len;

    strcpy(command, input_str);

    /* Split by ';' and '&' */
    for( str_ptr = strtok(input_str, "&;");
         NULL   != str_ptr;
         str_ptr = strtok(NULL, "&;") ) {

        /*
         * Make a place for the new job in the local p_jobs array
         */
        (*p_jobs) = (job_t *) realloc(*p_jobs, sizeof(job_t) * (*num_jobs + 1));
        (*p_rtypes) = (run_t *) realloc(*p_rtypes, sizeof(run_t) * (*num_jobs + 1));
        if( NULL == (*p_jobs)) {
            fprintf(stderr, "Error: Failed to allocate memory! Critical failure on %d!", __LINE__);
            exit(-1);
        }

        /* Initialize the job_t structure */
        (*p_jobs)[*num_jobs].full_command = trim(str_ptr);
        (*p_jobs)[*num_jobs].argc = 0;
        (*p_jobs)[*num_jobs].argv = NULL;


        len = strlen(str_ptr);
        (*p_rtypes)[*num_jobs] = FORE;
        if ('&' == command[(str_ptr - input_str) + len]) {
            (*p_rtypes)[*num_jobs] = BACK;
        } else if (';' == command[(str_ptr - input_str) + len]) {
            (*p_rtypes)[*num_jobs] = FORE;
        }

        /* Increment the number of p_jobs */
        (*num_jobs)++;
    }

    return 0;
}

int split_job_into_args(job_t *job)
{
    char * str_ptr  = NULL, * command = strdup(job->full_command);

    /* Start counting at 0 */
    job->argc = 0;

    /* Split by ' ' */
    for( str_ptr = strtok(command, " \n\t");
         NULL   != str_ptr;
         str_ptr = strtok(NULL, " \n\t") ) {

        /*
         * Make a place for the new argument in the argv array
         * +1 for NULL termination in the sizeof calculation below (for execvp)
         */
        job->argc++;
        job->argv = (char **)realloc(job->argv, (sizeof(char*) * ((job->argc)+1)));
        if( NULL == job->argv ) {
            fprintf(stderr, "Error: Failed to allocate memory! Critical failure on %d!", __LINE__);
            exit(-1);
        }

        /* Copy over the argument */
        job->argv[(job->argc)-1] = strdup(str_ptr);
        job->argv[job->argc]     = NULL;
    }

    free(command);

    return 0;
}

//void safe_free(void **ptr) {
//    if (NULL != *ptr) {
//        free(*ptr);
//        *ptr = NULL;
//    }
//}
