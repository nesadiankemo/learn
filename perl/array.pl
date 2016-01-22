#!/usr/bin/perl

use strict;
use warnings;

my @animals = ("camel", "llama", "owl");
my @numbers = (2, 33, 99);
my @mixed = ("camel", 45, 1.23);

print $animals[0], "\n";
print $animals[1], "\n";

print $mixed[$#mixed], "\n";
print "Number of elements in array animals is ", "@animals[0, 1]", "\n";

