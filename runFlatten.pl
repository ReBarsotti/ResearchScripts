#!/usr/bin/perl

$dataDir = "/P/stan/scratch/GlueX/RunPeriod-2018-08/analysis/ver17/tree_pi0eta__B4_M17_M7/merged/";
$outputDir = "/home/fs10/rebars/etapi0/flatten/";
$scriptDir = "/home/fs10/rebars/etapi0/flatten/";



@fileList = `ls -1 $dataDir | grep -v file | grep -v script`;

foreach $rootFile (@fileList){

	chomp $rootFile;
	if( $rootFile =~ /tree_pi0eta__B4_M17_M7_(\d+).root\z/){

		$fileTag = $1;

		$logFile = "$outputDir/$fileTag.log";
		$outFile = "flattened_$fileTag.root";
		
		$subScript = "sub_$fileTag.sh";

		open(SUBMIT,">$subScript");


		print "Submitting $subScript\n";
		print SUBMIT "#!/bin/sh\n";
		
		print SUBMIT "/P/stan/data/rebars/fs10/rebars/hd_utilities/FlattenForFSRoot/./flatten -in $dataDir/$rootFile -out $outputDir/$outFile -chi2 50";



		close SUBMIT;
		system ("sbatch $subScript");
		###system("/opt/gridengine/bin/lx-amd64/qsub $subScript");
	}
}
