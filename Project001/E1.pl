#!/usr/bin/perl
use strict;
use warnings;

#This is Euler Project 1 done in Perl.
my $total = 0;
$total += 3*333*334/2;
$total += 5*199*200/2;
$total -= 15*66*67/2;

print "The solution to Euler Problem 1 is: ", $total, "\n";