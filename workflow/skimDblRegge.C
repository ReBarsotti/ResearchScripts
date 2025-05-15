{
	FSModeCollection::addModeInfo("101_1")->addCategory("m101_1");


	TString naming = "./baryonMid/etapi_looserUnusedE_";

	FSCut::defineCut("etapi", "MASS2(2,3)>4.0");
	FSCut::defineCut("mcetapi", "MCMASS2(2,3)>4.0");

	FSCut::defineCut("t2", "MASS2(GLUEXTARGET,-1)>-2.");
	FSCut::defineCut("mct2", "MCMASS2(GLUEXTARGET,-1)>-2.");

	FSCut::defineCut("fasteta", "MASS2(B,-2)>-2.");
	FSCut::defineCut("fastpi", "MASS2(B,-3)>-2.");
	FSCut::defineCut("mcfasteta", "MCMASS2(B,-2)>-2.");
	FSCut::defineCut("mcfastpi", "MCMASS2(B,-3)>-2.");


	FSCut::defineCut("beamE", "EnPB> 8.2 && EnPB<8.8");
	FSCut::defineCut("mcbeamE", "MCEnPB> 8.2 &&MCEnPB<8.8");


	double bary1 = 4.25;
	double bary2 = 5.0;


//1.16 at 1.89, 1.4
//1.14 at 2.25, 1.48
	
	TString string1 =  "MASS2(1,2)>"+std::to_string(bary2)+ "&& MASS2(1,3)>"+std::to_string(bary1);	

	TString mcstring1 = "MCMASS2(1,2)>"+std::to_string(bary2)+ "&&MCMASS2(1,3)>"+std::to_string(bary1);

	FSCut::defineCut("etap", string1);
	FSCut::defineCut("pip", string1);
	FSCut::defineCut("mcetap", mcstring1);
	FSCut::defineCut("mcpip", mcstring1);


	TString fpi_accMC = naming + "accMC_fastpi.root";
	TString feta_accMC = naming + "accMC_fasteta.root"; 

	TString fpi_sideband = naming + "sideband_fastpi.root"; 
	TString feta_sideband = naming + "sideband_fasteta.root"; 
	
	TString fpi_signal = naming + "signal_fastpi.root"; 
	TString feta_signal = naming + "signal_fasteta.root";

	TString fpi_gen = naming + "genMC_fastpi.root"; 
	TString feta_gen = naming + "genMC_fasteta.root";



	FSModeTree::skimTree("./accMC_total/looserUnusedEAccMC.root","ntFSGlueX_101_1","",fpi_accMC,"CUT(etapi,fastpi,etap,pip,t2,beamE)");
	FSModeTree::skimTree("./accMC_total/looserUnusedEAccMC.root","ntFSGlueX_101_1","",feta_accMC,"CUT(etapi,fasteta,pip,etap,t2,beamE)");


	FSModeTree::skimTree("./data_final/looserUnusedEData_sideband.root","ntFSGlueX_101_1","",fpi_sideband,"CUT(etapi,fastpi,etap,pip,t2,beamE)");
	FSModeTree::skimTree("./data_final/looserUnusedEData_sideband.root","ntFSGlueX_101_1","",feta_sideband,"CUT(etapi,fasteta,pip,etap,t2,beamE)");

	FSModeTree::skimTree("./data_final/looserUnusedEData.root","ntFSGlueX_101_1","",feta_signal,"CUT(etapi,fasteta,pip,etap,t2,beamE)");
	FSModeTree::skimTree("./data_final/looserUnusedEData.root","ntFSGlueX_101_1","",fpi_signal,"CUT(etapi,fastpi,etap,pip,t2,beamE)");

	FSModeTree::skimTree("./genMC_final/genMC_total.root","ntFSGlueX_101_1","",feta_gen,"CUT(mcpip,mcetapi,mcfasteta,mcetap,mct2,mcbeamE)");
	FSModeTree::skimTree("./genMC_final/genMC_total.root","ntFSGlueX_101_1","",fpi_gen,"CUT(mcetapi,mcetap,mcfastpi,mcpip,mct2,mcbeamE)");
}
