#!/usr/bin/perl
use Cwd;

$workingDir = getcwd();

$nDivs =10;
@scales = (0, 0.96702801407, 0.97377040415, 0.97751598452, 0.98760154414, 0.99570890324,1.01278378739, 1.02941881661);
	for($k=1; $k<8; $k++){
		$cfgTempl = "$workingDir/fit_TEMPLATE.cfg";

		$fitName = "fit_fixedAlpha99_bin$k";
		$dataFile = "/Users/rebecca/workspace/files/baryonMid/etapi_looserUnusedE_signal_fasteta_bin$k\.root";
		$genMCFile = "/Users/rebecca/workspace/files/baryonMid/etapi_looserUnusedE_genMC_fasteta_bin$k\.root";
		$bkgndFile = "/Users/rebecca/workspace/files/baryonMid/etapi_looserUnusedE_sideband_fasteta_bin$k\.root";
		$accMCFile = "/Users/rebecca/workspace/files/baryonMid/etapi_looserUnusedE_accMC_fasteta_bin$k\.root";

		$pidataFile = "/Users/rebecca/workspace/files/baryonMid/etapi_looserUnusedE_signal_fastpi_bin$k\.root";
		$pigenMCFile = "/Users/rebecca/workspace/files/baryonMid/etapi_looserUnusedE_genMC_fastpi_bin$k\.root";
		$pibkgndFile = "/Users/rebecca/workspace/files/baryonMid/etapi_looserUnusedE_sideband_fastpi_bin$k\.root";
		$piaccMCFile = "/Users/rebecca/workspace/files/baryonMid/etapi_looserUnusedE_accMC_fastpi_bin$k\.root";
		print "Starting $j \n";

		open( CFGOUT, ">fit_fixedAlpha_bin$k\.cfg" );
		open( CFGIN, $cfgTempl );

		while( <CFGIN> ){

			s/PIDATAFILE/$pidataFile/;
			s/PIACCMCFILE/$piaccMCFile/;
			s/PIGENMCFILE/$pigenMCFile/;
			s/PIBKGNDFILE/$pibkgndFile/g;
			s/SCALEFACTOR/$scales[$k]/;

			s/ETADATAFILE/$dataFile/;
			s/ETAACCMCFILE/$accMCFile/;
			s/ETAGENMCFILE/$genMCFile/;
			s/FITNAME/$fitName/;

			s/ETABKGNDFILE/$bkgndFile/g;
			print CFGOUT $_;
		}

		close CFGOUT;
		close CFGIN;



	}

