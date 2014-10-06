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

###############################################
# Tests - Part 2
###############################################
mycheck-mypart2: mysh mycheck-mypart2-interactive mycheck-mypart2-batch mycheck-mypart2-levels

mycheck-mypart2-interactive: mysh mycheck-mypart2-1 mycheck-mypart2-2
mycheck-mypart2-batch: mysh mycheck-mypart2-3 mycheck-mypart2-4
mycheck-mypart2-levels: part2-level01 part2-level02 part2-level03 part2-level04 part2-level05 part2-level06 part2-level07 part2-level08 part2-level09 part2-level10 part2-level11 part2-level12 part2-level13

############ Interactive
T_Z2_B_1=./mysh
T_Z2_I_1=tests/file4.txt
T_Z2_O_1=tests/file4-output.txt
mycheck-mypart2-1:
	@given-tests/check.pl I "./mysh" $(T_Z2_I_1) 11 11 0 $(T_Z2_O_1)

T_Z2_B_2=./mysh
T_Z2_I_2=tests/file5.txt
T_Z2_O_2=tests/file5-output.txt
mycheck-mypart2-2:
	@given-tests/check.pl I "./mysh" $(T_Z2_I_2) 6 12 3 $(T_Z2_O_2)

############ Batch
T_Z2_B_3=./mysh
T_Z2_I_3=tests/file6.txt
T_Z2_O_3=tests/file6-output.txt
mycheck-mypart2-3:
	@given-tests/check.pl B "./mysh" $(T_Z2_I_3) 12 26 22 $(T_Z2_O_3)

T_Z2_B_4=./mysh
T_Z2_I_4="tests/file4.txt tests/file5.txt"
T_Z2_O_4=tests/file02-output.txt
mycheck-mypart2-4:
	@given-tests/check.pl B "./mysh" $(T_Z2_I_4) 17 23 3 $(T_Z2_O_4)


############# Levels
T_Z2_I_LEVEL1=given-tests/part2/level01.txt
mypart2-level01:
	given-tests/check.pl B "./mysh" $(T_Z2_I_LEVEL1) 6 6 0

T_Z2_I_LEVEL2=given-tests/part2/level02.txt
mypart2-level02:
	@given-tests/check.pl B "./mysh" $(T_Z2_I_LEVEL2) 7 14 4

T_Z2_I_LEVEL3=given-tests/part2/level03.txt
mypart2-level03:
	@given-tests/check.pl B "./mysh" $(T_Z2_I_LEVEL3) 9 14 4

T_Z2_I_LEVEL4=given-tests/part2/level04.txt
mypart2-level04:
	@given-tests/check.pl B "./mysh" $(T_Z2_I_LEVEL4) 5 5 0

T_Z2_I_LEVEL5=given-tests/part2/level05.txt
mypart2-level05:
	@given-tests/check.pl B "./mysh" $(T_Z2_I_LEVEL5) 31 31 0

T_Z2_I_LEVEL6=given-tests/part2/level06.txt
mypart2-level06:
	@given-tests/check.pl B "./mysh" $(T_Z2_I_LEVEL6) 33 35 25

T_Z2_I_LEVEL7=given-tests/part2/level07.txt
mypart2-level07:
	@given-tests/check.pl B "./mysh" $(T_Z2_I_LEVEL7) 5 7 5

T_Z2_I_LEVEL8=given-tests/part2/level08.txt
mypart2-level08:
	@given-tests/check.pl B "./mysh" $(T_Z2_I_LEVEL8) 11 14 7

T_Z2_I_LEVEL9=given-tests/part2/level09.txt
mypart2-level09:
	@given-tests/check.pl B "./mysh" $(T_Z2_I_LEVEL9) 100 100 0

T_Z2_I_LEVEL10=given-tests/part2/level10.txt
mypart2-level10:
	@given-tests/check.pl B "./mysh" $(T_Z2_I_LEVEL10) 100 100 100

T_Z2_I_LEVEL11=given-tests/part2/level11.txt
mypart2-level11:
	@given-tests/check.pl B "./mysh" $(T_Z2_I_LEVEL11) 1 1 0

T_Z2_I_LEVEL12=given-tests/part2/level12.txt
mypart2-level12:
	@given-tests/check.pl B "./mysh" $(T_Z2_I_LEVEL12) 1000 1000 0

T_Z2_I_LEVEL13=given-tests/part2/level13.txt
mypart2-level13:
	@given-tests/check.pl B "./mysh" $(T_Z2_I_LEVEL13) 10 10 0