//
// Created by Sanhu Li on 14-10-3.
// Copyright (c) 2014 lsh. All rights reserved.
//


#ifndef __support_H_
#define __support_H_

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stdio.h"

#define MAX_COMMAND_LINE 1024

typedef enum run_t {
    BACK,
    FORE
} run_t;

typedef struct job_t {
    char * full_command;
    int argc;
    char ** argv;
} job_t;

char * trim(const char * src);

int split_input_into_jobs(char *input_str, int *num_jobs, job_t **jobs, run_t **p_rtypes);
int split_job_into_args(job_t *job);

//void safe_free(void ** ptr);

#endif //__support_H_
