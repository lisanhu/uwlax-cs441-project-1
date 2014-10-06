# CS441/541 Project 01 - Part 2
**Author:** *Huifeng Zhang, Sanhu Li*

**Date:** *Oct. 5, 2014*

---
## Description:

It is a simple self-made shell program.

This program is a more professional version of Projecet 01 - Part 1, in this version, the builtin function history and jobs are implemented, it is capable of either interactive or batch mode, which can read command from user input or from files.

---
## Tips:
while processing command "exit", the program will be terminated directly if no process is still running. It will display a message indicating how many processes are still running in the background, and will wait until their finishing to exit the program. 

---
## How to compile:
A Makefile is provided in this assignment.
To compile the application, use the command:

    $ make


To remove the application, please use:

    $ make clean

---
## How to run:
### Interactive mode:
To run the program from the command line, simply execute the following command just as you did to the local shell before.

    $ ./mysh

### batch mode:

    $ ./mysh [input file name] [...]

You can enter several file names at the same time.

---
## Example(s):
This example runs with a simple input command `./mysh tests/file4.txt`.(note: when user run this command, the date will be different because it displays the current time)

```
Sun Oct  5 19:00:26 CDT 2014
/home/zhang.huif/myproject-1
Sun Oct  5 19:00:26 CDT 2014
/home/zhang.huif/myproject-1
Sun Oct  5 19:00:26 CDT 2014
/home/zhang.huif/myproject-1
ls: cannot access test: No such file or directory
..:
cs441-f2014-project-0  myproject0  myproject-1	tmp
given-tests  mysh    mysh.h  support.c	support.o
Makefile     mysh.c  ReadMe  support.h	tests
file01-output.txt  file2-output.txt  file4.txt	       file6.txt
file02-output.txt  file2.txt	     file5-output.txt  file-output.txt
file1-output.txt   file3.txt	     file5.txt	       file.txt
file1.txt	   file4-output.txt  file6-output.txt  Makefile
zhang.huif
Sun Oct  5 19:00:26 CDT 2014


-------------------------------
Total number of jobs               = 11
Total number of jobs in history    = 11
Total number of jobs in background = 0
-------------------------------
```
This example runs with a simple input command `./mysh` to start the shell, user should input one command each time to process.

```
mysh$ date
Sun Oct  5 19:16:10 CDT 2014

mysh$ /bin/pwd
/home/zhang.huif/myproject-1

mysh$ ls tests ..
..:
cs441-f2014-project-0  myproject0  myproject-1	tmp

tests:
file01-output.txt  file2-output.txt  file4.txt	       file6.txt
file02-output.txt  file2.txt	     file5-output.txt  file-output.txt
file1-output.txt   file3.txt	     file5.txt	       file.txt
file1.txt	   file4-output.txt  file6-output.txt  Makefile

mysh$ /bin/date;pwd;/bin/ls tests ..   
Sun Oct  5 19:17:02 CDT 2014
/home/zhang.huif/myproject-1
..:
cs441-f2014-project-0  myproject0  myproject-1	tmp

tests:
file01-output.txt  file2-output.txt  file4.txt	       file6.txt
file02-output.txt  file2.txt	     file5-output.txt  file-output.txt
file1-output.txt   file3.txt	     file5.txt	       file.txt
file1.txt	   file4-output.txt  file6-output.txt  Makefile

mysh$ /bin/date
Sun Oct  5 19:17:09 CDT 2014

mysh$ /bin/sleep 5 & sleep 4 & sleep 3 & /bin/sleep 3 &
mysh$ jobs
[1]	Running	/bin/sleep 5
[2]	Running	sleep 4
[3]	Running	sleep 3
[4]	Running	/bin/sleep 3
mysh$ jobs
[1]	Done	/bin/sleep 5
[2]	Done	sleep 4
[3]	Done	sleep 3
[4]	Done	/bin/sleep 3
mysh$ jobs
mysh$ 

```
---
## How to test:

To use the built-in test:

    make check-part2
    
To use the customed test:

    make mycheck-mypart2
    
---

## Known bugs & limitations:

If you find any bugs, please report to [li.sanh@uwlax.edu](mailto:li.sanh@uwlax.edu) or [zhang.huif@uwlax.edu](mailto:zhang.huif@uwlax.edu)



