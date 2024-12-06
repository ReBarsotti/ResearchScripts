#!/usr/bin/perl

$dataDir = "/home/fs10/rebars/etapi0/flatten/";
$outputDir = "/home/fs10/rebars/etapi0/tighterPi0Window/";
$scriptDir = "/home/fs10/rebars/etapi0/tighterPi0Window/";


$template = "/home/fs10/rebars/etapi0/skim.C";


@fileList = `ls -1 $dataDir | grep -v file | grep -v script`;

foreach $rootFile (@fileList){

	chomp $rootFile;
	if( $rootFile =~ /flattened_(\d+).root\z/){

		$fileTag = $1;

		$logFile = "$outputDir/6_$fileTag.log";
		$outFile = "$outputDir/fullSkim_$fileTag.root";
		$genFile = "$outputDir/genSkim_$fileTag.root";
		$sboutFile = "$outputDir/fullSkim_sideband_$fileTag.root";
		$script = "skim6_$fileTag.C";
		$subScript = "sub6_$fileTag.sh";

		open( TEMP, "$template" );
		open( OUT, ">$script" );
		open(SUBMIT,">$subScript");

		while( <TEMP> ){
			s/INPUT/\"$dataDir\/$rootFile\"/g;
			s/OUTPUT/\"$outFile\"/g;
			s/SBOUT/\"$sboutFile\"/g;
			s/GEN/\"$genFile\"/g;
			print OUT;
		}
		print "Submitting $script\n";
		print SUBMIT "#!/bin/sh\n";
		print SUBMIT "export FSROOT=/home/fs10/rebars/FSRoot\n";
		print SUBMIT "/P/stan/data/shared/ROOT/6.30.02/bin/root -b -q $script";

		close OUT;
		close TEMP;

		close SUBMIT;
		system("chmod 777 $subScript");
		system("/usr/bin/sbatch $subScript");

	}
}
