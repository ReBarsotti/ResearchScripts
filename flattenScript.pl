#!/usr/bin/perl

$dataDir = "/lustre19/expphy/volatile/halld/home/rebars/etapi/root/trees/";
$outputDir = "/lustre19/expphy/volatile/halld/home/rebars/FlattenForFSRoot/testMC/";
@fileList = `ls -1 $dataDir | grep -v file | grep -v script`;

foreach $hddmFile (@fileList){

        chomp $hddmFile;

        if($hddmFile =~ /tree_pi0eta__B4_M7_M17_python_(\d+_\d+)\.root/ ){
                        $fileTag = $1;
                        $hddmFile = $dataDir."/".$hddmFile;

                        $outFile = "$fileTag.root";

                        system( "flatten -in $hddmFile -mc 1 -mctag 0_101_1 -out $outFile -chi2 50" );

        }
}
