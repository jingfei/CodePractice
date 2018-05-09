#!/usr/bin/perl

use strict;
use warnings;
use LWP::Simple;
# solve "Wide character in print" problem
use utf8;
binmode(STDIN, ':encoding(utf8)');
binmode(STDOUT, ':encoding(utf8)');
binmode(STDERR, ':encoding(utf8)');

# trim subroutine (delete all the blanks)
sub trim{
	(my $string) = @_;
	for ($string){
		s/^\s+//;
		s/\s+$//;
	}
	return $string;
}

# GetMovie function
sub GetMovie{
	(my $link) = @_;
	my $code = get($link) or die "cannot retrieve code\n";
	my %movie;
	my @Name1 = ( $code =~ /<div class="film_title">(.+?)<\/div>/gs );
	for(my $i=0; $i<=$#Name1; $i++){
		# get movie name
		my @tmp = ( $Name1[$i] =~ />(.*?)<\/a>/ );
		$Name1[$i] = $tmp[0];
	}
	my @Name2 = ( $code =~ /<div class="showtime_area">(.+?)<!--showtime_area end-->/gs );
	for(my $i=0; $i<=$#Name2; $i++){
		# get movie version
		my @version = trim( ( $Name2[$i] =~ /<div class="version">(.*?)<\/div>/gs ) );
		if($version[0]){ 
			my @tmp = ( $version[0] =~ />(.*?) <\/font>/ );
			if($tmp[0]){ $Name1[$i] .= (' (' . $tmp[0] . ')'); }
			else{ $Name1[$i] .= (' (' . $version[0] . ')'); }
		}
		# get movie time
		my @time =  ( $Name2[$i] =~ /(?i)<li>(.*?)(?i)<\/li>/g );
		# move away "訂票" if the website has that...
		for(my $j=0; $j<=$#time; $j++){
			my @tmp = ( $time[$j] =~ />(.*?)(?i)&nbsp;/gs );
			if(@tmp){ $time[$j]=$tmp[0]; }
		}
		# push the movie into array
		push ( @{$movie{$Name1[$i]}}, @time ); 
	}
	foreach my $key (keys %movie){
		print "\t".$key."\n";
		foreach my $i (values $movie{$key}){
			print "\t".$i."\n";
		}
		print "\n";
	}
	print "\n";
}

# movie1: 台南國賓影城
print "台南國賓影城:\n\n";
my $link1 = 'http://www.atmovies.com.tw/showtime/theater_t06608_a06.html';
GetMovie($link1);

# movie2: 台南新光影城
print "台南新光影城:\n\n";
my $link2 = 'http://www.atmovies.com.tw/showtime/theater_t06607_a06.html';
GetMovie($link2);

# movie3: 台南威秀影城
print "台南威秀影城:\n\n";
my $link3 = 'http://www.atmovies.com.tw/showtime/theater_t06609_a06.html';
GetMovie($link3);


