#!/usr/bin/perl

use strict;
use warnings;

my $email = "liangjting\@gmail.com";
if($email =~ /([^@]+)@(.+)/){
	print "Username is $1\n";
	print "Hostname is $2\n";
}

my $line = "other regexp features other 124453563 90987878877";
while($line =~ /(\d{7,})/g){
	print "maybe a phone number: $1\n";
	
}
