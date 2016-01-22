#!/usr/bin/perl

use strict;
use warnings;

sub logger {
	my $logmessage = shift;
	open my $logfile, ">>", "my.log" or die "Could not open my.log: $!";
	print $logfile $logmessage;
}
# '>' means write while ">>" means add.

logger("We have a logger subroutine!\n");
