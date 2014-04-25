#!/usr/bin/perl
use strict;
use warnings;

#Euler problem 2
#Display the sum of all Fibonacci numbers below 4 million.

my $Fn = 0;
my $F1 = 1;
my $F2 = 2;

while($F2 < 4000000)
{
	if($F2%2 == 0)
	{  $Fn += 0;  }
	else
	{  $Fn += $F2;  }
	$F2 += $F1;
	$F1 = $F2 - $F1;
}

print $Fn;