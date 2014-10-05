//
// Created by Sanhu Li on 14-10-3.
// Copyright (c) 2014 lsh. All rights reserved.
//


#ifndef __support_H_
#define __support_H_

#import <string.h>
#include <ctype.h>
#import <stdlib.h>
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

typedef struct treeset {
    int val;
    struct treeset *left;
    struct treeset *right;
} treeset;

char * trim(const char * src);

job_t * delete(job_t * src, int length, int index);

job_t * jobcpy(job_t * dest, int dest_start, job_t * src, int src_start, int length);

int split_input_into_jobs(char *input_str, int *num_jobs, job_t **jobs, run_t **p_rtypes);
int split_job_into_args(job_t *job);

#endif //__support_H_
