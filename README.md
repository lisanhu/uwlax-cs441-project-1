# CS441/541
## Project 01 - Part 1
Author: Huifeng Zhang, Sanhu Li
Date 09/24/2014
-------------------------
Description:
It a simple self made shell program.
This program is capable of separate strings input by user or read a file and separate each job and display.
And can tell the difference between builtin, foreground and background commands.
As well, at the end, the total numbers of all jobs and foreground and background jobs will be output.
-------------------------
How to compile:
-------------------------------
-------------------------
A Makefile is supplied with this assignment.
To compile the application:
   make

To clean the build:
   make clean
-------------------------

How to run:
-------------------------------
-------------------------
To run the program from the command line simply execute the following command.
You may optionally pass arguments to the command.
./mysh

Example(s):
-------------------------------
-------------------------
This example runs with a simple input command "./mysh tests/file.txt" provided by the
user.
-------------------------
Job 1 : "/bin/date"
Job 2 : "/bin/pwd"
Job 3 : "/bin/ls" [tests] [..]
Job 4x: "history"
Job 5 : "/bin/pwd"
Job 6 : "ls" [..]
Job 7*: "sleep" [5]
Job 8*: "/bin/sleep" [3]
-------------------------------
Total number of jobs			   = 7
Total number of jobs in history	   = 8
Total number of jobs in background = 2
-------------------------------

This example runs with a simple input command "./mysh" to start the shell, provided by the
user.
-------------------------------
mysh$ date
Job 1 : "date"
mysh$ /bin/pwd
Job 2 : "/bin/pwd"
mysh$ ls tests ..
Job 3 : "ls" [tests] [..] mysh$
mysh$ /bin/date; pwd ; /bin/ls tests .. Job 4 : "/bin/date"
Job 5 : "pwd"
Job 6 : "/bin/ls" [tests] [..]
mysh$ sleep 5 & /bin/sleep 4 &
Job 7*: "sleep" [5]
Job 8*: "/bin/sleep" [4]
mysh$ jobs
Job 9x: "jobs"
mysh$ history
Job 10x: "history"
mysh$ exit
Job 11x: "exit" -------------------------------
Total number of jobs
Total number of jobs in history
Total number of jobs in background = 2

-------------------------------
Known bugs & limitations:
-------------------------