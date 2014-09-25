/*
 * Sanhu Li
 *
 * CS441/541: Project 1 Part 1
 * Sep. 25, 2014
 */
#ifndef MYSHELL_H
#define MYSHELL_H

#include "support.h"
#include "stdbool.h"

/* For fork, exec, sleep */
#include <sys/types.h>
#include <unistd.h>
/* For waitpid */
#include <sys/wait.h>

/******************************
 * Defines
 ******************************/
#define NUM_BUILT_IN 3


/******************************
 * Structures
 ******************************/


/******************************
 * Global Variables
 ******************************/
char built_ins[NUM_BUILT_IN][MAX_COMMAND_LINE] = {"history", "jobs", "exit"};

/******************************
 * Function declarations
 ******************************/
int interactive_mode();

int batch_mode(int argc, char ** argv);

void print_statistics(int num_jobs, int num_history, int num_background);

bool is_built_in(char * command);

void clean_jobs(job_t * loc_jobs, int num_jobs);

void shut_down(job_t * loc_jobs, int num_jobs, int num_history, int num_background);

#endif /* MYSHELL_H */
