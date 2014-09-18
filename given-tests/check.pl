#!/usr/bin/perl

use strict;

###########################################
# Parse Command Line Arguments
# [B/I] [Binary] [Input file] [Num Jobs] [History] [Background] [OUTPUT]
###########################################
if( scalar(@ARGV) < 6 ) {
    print "ERROR: Not enough arguments\n";
    exit -1;
}

my $isbatch        = ($ARGV[0] =~ /b/i ? 1 : 0);
my $binary         = $ARGV[1];
my $input          = $ARGV[2];
my $num_jobs       = int($ARGV[3]);
my $num_history    = int($ARGV[4]);
my $num_background = int($ARGV[5]);
my $exp_output     = $ARGV[6];

###########################################
# Diagnostics
###########################################
print "-"x70 . "\n";
print "Running the command:\n";
if( $isbatch ) {
    print "\tshell\$ $binary $input\n";
} else {
    print "\tshell\$ $binary < $input\n";
}

###########################################
# Run the command and gather all output
###########################################
my @output;
if( $isbatch ) {
    @output = `$binary $input 2>&1`;
} else {
    @output = `$binary < $input 2>&1`;
}

###########################################
# Check the final totals
###########################################
my $num_errors = 0;
my $num;
my $found_num_jobs = 1;
my $found_num_jobs_bg = 1;
my $found_num_jobs_h = 1;

foreach my $line (@output) {

    if( $line =~ /Total number of jobs/i ) {
        if( $line =~ /history/i ) {
            $line =~ /\d+/;
            $num = $&;
            $found_num_jobs_h = 0;

            if( int($num) != $num_history ) {
                printf("Error: The number of jobs (history) reported was expected to be %d, but was reported as %d\n", $num_history, $num);
                ++$num_errors;
            }
        }
        elsif( $line =~ /background/i ) {
            $line =~ /\d+/;
            $num = $&;
            $found_num_jobs_bg = 0;

            if( int($num) != $num_background ) {
                printf("Error: The number of jobs (background) reported was expected to be %d, but was reported as %d\n", $num_background, $num);
                ++$num_errors;
            }
        }
        else {
            $line =~ /\d+/;
            $num = $&;
            $found_num_jobs = 0;

            if( int($num) != $num_jobs ) {
                printf("Error: The number of jobs (total) reported was expected to be %d, but was reported as %d\n", $num_jobs, $num);
                ++$num_errors;
            }
        }
    }
}

if( 1 == $found_num_jobs ) {
    printf("Error: Did not found the output for the \"Total number of jobs\"\n");
    ++$num_errors;
}
if( 1 == $found_num_jobs_h ) {
    printf("Error: Did not found the output for the \"Total number of jobs in history\"\n");
    ++$num_errors;
}
if( 1 == $found_num_jobs_bg ) {
    printf("Error: Did not found the output for the \"Total number of jobs in background\"\n");
    ++$num_errors;
}

if( 0 == $num_errors ) {
    printf("Passed: Job totals\n");
}

###########################################
# Check the content of the output
# TODO
###########################################
my @all_exp = ();

if( defined($exp_output) ) {
    ;
}

exit 0;
