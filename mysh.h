//
// Created by Sanhu Li on 14-10-3.
// Copyright (c) 2014 lsh. All rights reserved.
//


#ifndef __main_H_
#define __main_H_

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <semaphore.h>
#include "support.h"

#define MAX_LINE 1024

typedef enum job_s_t {
    DONE, RUNNING, SHOWN
} job_s_t;

// All jobs in history, builtin jobs included
job_t *jobs;
// Run type for all jobs in history, FORE or BACK
run_t *run_types;
/*
    num_jobs: length of all jobs in history
    pids: hold all the pids for the child processes
    p_num: num of child processes, also thought to be num of jobs
    jids: corresponding job index for a certain child process
*/
int num_jobs, *pids, p_num, *jids;
// states: state for child processes
job_s_t *states;


void inter_mode();
void batch_mode(int argc, const char *argv[]);
void my_exit();
void my_jobs();
void my_history();
void my_process(job_t job, run_t run_type, int jid);

#endif //__main_H_
