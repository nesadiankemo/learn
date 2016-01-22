#!/usr/bin/perl

use strict;
use warnings;

open(my $in, "<", "hash.pl") or die "Can't open hash.pl: $!";

my $line = <$in>;

while (<$in>) {
	printf "$_";
}

close $in or die "$in: $!";
