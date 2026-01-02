#!/usr/bin/perl



for( $k = 1; $k < 8; ++$k ){

	$seed = $j * 100 + $i*11 ;  

	print "Fitting in bin $i...\n";
	print "Seed is $seed...\n";
	system( "fit -c fit_fixedAlpha_bin$k\.cfg -rs $seed -r 15" );



}
