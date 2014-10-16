#!usr/bin/perl

use strict;
use warnings;
use LWP::Simple;

# movie1: 台南國賓影城
my $link1 = 'http://www.atmovies.com.tw/showtime/theater_t06608_a06.html';
my $movie1 = get($link1) or die "cannot retrieve code\n";
open(DATA,">Movie1.htm") or "open file error";


