#
# Josh Hursey
# Sept. 15, 2014
#
# Given set of correctness tests
# Note: There will be more added when assessing your final grade.
#       These tests are -not- comprehensive!
#

#
# Tests
#
check: mysh
	@echo "Which check would you like to run?"
	@echo "For Part 1 testing use:"
	@echo "    make check-part1"
	@echo "For Part 2 testing use:"
	@echo "    make check-part2"



###############################################
# Tests - Part 1
###############################################
check-part1: mysh check-part1-interactive check-part1-batch check-part1-levels

check-part1-interactive: mysh check-part1-1 check-part1-2
check-part1-batch: mysh check-part1-3 check-part1-4
check-part1-levels: part1-level1 part1-level2 part1-level3 part1-level4 part1-level5 part1-level6 part1-level7 part1-level8 part1-level9

T_P1_B_1=./mysh
T_P1_I_1=given-tests/part1/part1-1-input.txt
T_P1_O_1=given-tests/part1/part1-1-output.txt
check-part1-1:
	@given-tests/check.pl I "./mysh" $(T_P1_I_1) 1 1 0 $(T_P1_O_1)

T_P1_B_2=./mysh
T_P1_I_2=given-tests/part1/part1-2-input.txt
T_P1_O_2=given-tests/part1/part1-2-output.txt
check-part1-2:
	@given-tests/check.pl I "./mysh" $(T_P1_I_2) 7 8 2 $(T_P1_O_2)

############
T_P1_B_3=./mysh
T_P1_I_3=given-tests/part1/part1-1-input.txt
T_P1_O_3=given-tests/part1/part1-3-output.txt
check-part1-3:
	@given-tests/check.pl B "./mysh" $(T_P1_I_3) 1 1 0 $(T_P1_O_3)

T_P1_B_4=./mysh
T_P1_I_4="given-tests/part1/part1-1-input.txt given-tests/part1/part1-2-input.txt"
T_P1_O_4=given-tests/part1/part1-4-output.txt
check-part1-4:
	@given-tests/check.pl B "./mysh" $(T_P1_I_4) 8 9 2 $(T_P1_O_4)

############# Levels
T_P1_I_LEVEL1=given-tests/part1/level1.txt
part1-level1:
	@given-tests/check.pl B "./mysh" $(T_P1_I_LEVEL1) 3 3 0

T_P1_I_LEVEL2=given-tests/part1/level2.txt
part1-level2:
	@given-tests/check.pl B "./mysh" $(T_P1_I_LEVEL2) 6 6 0

T_P1_I_LEVEL3=given-tests/part1/level3.txt
part1-level3:
	@given-tests/check.pl B "./mysh" $(T_P1_I_LEVEL3) 11 15 11

T_P1_I_LEVEL4=given-tests/part1/level4.txt
part1-level4:
	@given-tests/check.pl B "./mysh" $(T_P1_I_LEVEL4) 100 100 0

T_P1_I_LEVEL5=given-tests/part1/level5.txt
part1-level5:
	@given-tests/check.pl B "./mysh" $(T_P1_I_LEVEL5) 100 100 100

T_P1_I_LEVEL6=given-tests/part1/level6.txt
part1-level6:
	@given-tests/check.pl B "./mysh" $(T_P1_I_LEVEL6) 1 1 0

T_P1_I_LEVEL7=given-tests/part1/level7.txt
part1-level7:
	@given-tests/check.pl B "./mysh" $(T_P1_I_LEVEL7) 1000 1000 0

T_P1_I_LEVEL8=given-tests/part1/level8.txt
part1-level8:
	@given-tests/check.pl B "./mysh" $(T_P1_I_LEVEL8) 2100 2100 0

T_P1_I_LEVEL9=given-tests/part1/level9.txt
part1-level9:
	@given-tests/check.pl B "./mysh" $(T_P1_I_LEVEL9) 10 10 0


###############################################
# Tests - Part 2
###############################################
check-part2: mysh check-part2-levels

#check-part2: mysh
#	@echo "Not ready yet..."

check-part2-levels: part2-level01 part2-level02 part2-level03 part2-level04 part2-level05 part2-level06 part2-level07 part2-level08 part2-level09 part2-level10 part2-level11 part2-level12 part2-level13

############# Levels
T_P2_I_LEVEL1=given-tests/part2/level01.txt
part2-level01:
	given-tests/check.pl B "./mysh" $(T_P2_I_LEVEL1) 6 6 0

T_P2_I_LEVEL2=given-tests/part2/level02.txt
part2-level02:
	@given-tests/check.pl B "./mysh" $(T_P2_I_LEVEL2) 7 14 4

T_P2_I_LEVEL3=given-tests/part2/level03.txt
part2-level03:
	@given-tests/check.pl B "./mysh" $(T_P2_I_LEVEL3) 9 14 4

T_P2_I_LEVEL4=given-tests/part2/level04.txt
part2-level04:
	@given-tests/check.pl B "./mysh" $(T_P2_I_LEVEL4) 5 5 0

T_P2_I_LEVEL5=given-tests/part2/level05.txt
part2-level05:
	@given-tests/check.pl B "./mysh" $(T_P2_I_LEVEL5) 31 31 0

T_P2_I_LEVEL6=given-tests/part2/level06.txt
part2-level06:
	@given-tests/check.pl B "./mysh" $(T_P2_I_LEVEL6) 33 35 25

T_P2_I_LEVEL7=given-tests/part2/level07.txt
part2-level07:
	@given-tests/check.pl B "./mysh" $(T_P2_I_LEVEL7) 5 7 5

T_P2_I_LEVEL8=given-tests/part2/level08.txt
part2-level08:
	@given-tests/check.pl B "./mysh" $(T_P2_I_LEVEL8) 11 14 7

T_P2_I_LEVEL9=given-tests/part2/level09.txt
part2-level09:
	@given-tests/check.pl B "./mysh" $(T_P2_I_LEVEL9) 100 100 0

T_P2_I_LEVEL10=given-tests/part2/level10.txt
part2-level10:
	@given-tests/check.pl B "./mysh" $(T_P2_I_LEVEL10) 100 100 100

T_P2_I_LEVEL11=given-tests/part2/level11.txt
part2-level11:
	@given-tests/check.pl B "./mysh" $(T_P2_I_LEVEL11) 1 1 0

T_P2_I_LEVEL12=given-tests/part2/level12.txt
part2-level12:
	@given-tests/check.pl B "./mysh" $(T_P2_I_LEVEL12) 1000 1000 0

T_P2_I_LEVEL13=given-tests/part2/level13.txt
part2-level13:
	@given-tests/check.pl B "./mysh" $(T_P2_I_LEVEL13) 10 10 0
