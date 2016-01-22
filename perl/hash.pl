#!/usr/bin/perl

use strict;
use warnings;

my %fruit_color = (
	apple => "red",
	banana => "yellow",
);
my @fruits = keys %fruit_color;
my @colors = values %fruit_color;
my $variables = {
	scalar	=> {
		 description => "single item",
		 sigil => '$',	
		},
	array	=> {
		 description => "ordered list of items",	
		 sigil => '@',
		},
	hash	=> {
		 description => "key/value pairs",
	 	 sigil => '%',	 
		},

};

print $fruit_color{"apple"}, "\n";
print "@fruits \n";
print "@colors \n";
print "Scalars begin with a $variables->{'scalar'}->{'sigil'}\n"
