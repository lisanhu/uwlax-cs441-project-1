#
# Huifeng Zhang	
# Sept. 24, 2014
#
# Given set of correctness tests
# 
#       These tests are -not- comprehensive!
#

#
# Tests
#
mycheck: mysh
	@echo "Which check would you like to run?"
	@echo "For Part 1 testing use:"
	@echo "    make mycheck-mypart1"
	@echo "For Part 2 testing use:"
	@echo "    make mycheck-mypart2"

###############################################
# Tests - Part 1
###############################################
mycheck-mypart1: mysh mycheck-mypart1-interactive mycheck-mypart1-batch mycheck-mypart1-levels

mycheck-mypart1-interactive: mysh mycheck-mypart1-1 mycheck-mypart1-2
mycheck-mypart1-batch: mysh mycheck-mypart1-3 mycheck-mypart1-4
mycheck-mypart1-levels: mypart1-level1 mypart1-level2 mypart1-level3 mypart1-level4 mypart1-level5 mypart1-level6 mypart1-level7 mypart1-level8 mypart1-level9

T_Z1_B_1=./mysh
T_Z1_I_1=tests/file.txt
T_Z1_O_1=tests/file-output.txt
mycheck-mypart1-1:
	@given-tests/check.pl I "./mysh" $(T_Z1_I_1) 7 8 2 $(T_Z1_O_1)

T_Z1_B_2=./mysh
T_Z1_I_2=tests/file1.txt
T_Z1_O_2=tests/file1-output.txt
mycheck-mypart1-2:
	@given-tests/check.pl I "./mysh" $(T_Z1_I_2) 3 3 0 $(T_Z1_O_2)

############
T_Z1_B_3=./mysh
T_Z1_I_3=tests/file2.txt
T_Z1_O_3=tests/file2-output.txt
mycheck-mypart1-3:
	@given-tests/check.pl B "./mysh" $(T_Z1_I_3) 4 6 2 $(T_Z1_O_3)

T_Z1_B_4=./mysh
T_Z1_I_4="tests/file.txt tests/file1.txt"
T_Z1_O_4=tests/file01-output.txt
mycheck-mypart1-4:
	@given-tests/check.pl B "./mysh" $(T_Z1_I_4) 7 8 2 $(T_Z1_O_4)

############# Levels
T_Z1_I_LEVEL1=given-tests/part1/level1.txt
mypart1-level1:
	@given-tests/check.pl B "./mysh" $(T_Z1_I_LEVEL1) 3 3 0

T_Z1_I_LEVEL2=given-tests/part1/level2.txt
mypart1-level2:
	@given-tests/check.pl B "./mysh" $(T_Z1_I_LEVEL2) 6 6 0

T_Z1_I_LEVEL3=given-tests/part1/level3.txt
mypart1-level3:
	@given-tests/check.pl B "./mysh" $(T_Z1_I_LEVEL3) 11 15 11

T_Z1_I_LEVEL4=given-tests/part1/level4.txt
mypart1-level4:
	@given-tests/check.pl B "./mysh" $(T_Z1_I_LEVEL4) 100 100 0

T_Z1_I_LEVEL5=given-tests/part1/level5.txt
mypart1-level5:
	@given-tests/check.pl B "./mysh" $(T_Z1_I_LEVEL5) 100 100 100

T_Z1_I_LEVEL6=given-tests/part1/level6.txt
mypart1-level6:
	@given-tests/check.pl B "./mysh" $(T_Z1_I_LEVEL6) 1 1 0

T_Z1_I_LEVEL7=given-tests/part1/level7.txt
mypart1-level7:
	@given-tests/check.pl B "./mysh" $(T_Z1_I_LEVEL7) 1000 1000 0

T_Z1_I_LEVEL8=given-tests/part1/level8.txt
mypart1-level8:
	@given-tests/check.pl B "./mysh" $(T_Z1_I_LEVEL8) 2100 2100 0

T_Z1_I_LEVEL9=given-tests/part1/level9.txt
mypart1-level9:
	@given-tests/check.pl B "./mysh" $(T_Z1_I_LEVEL9) 10 10 0
