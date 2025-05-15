{
	FSModeCollection::addModeInfo("101_1")->addCategory("m101_1");


	TString sig_eta = "./baryonMid/etapi_looserUnusedE_signal_fasteta";	
	TString gen_eta = "./baryonMid/etapi_looserUnusedE_genMC_fasteta";	
	TString acc_eta = "./baryonMid/etapi_looserUnusedE_accMC_fasteta";	
	TString sb_eta = "./baryonMid/etapi_looserUnusedE_sideband_fasteta";	
	
	TString sig_pi = "./baryonMid/etapi_looserUnusedE_signal_fastpi";	
	TString gen_pi = "./baryonMid/etapi_looserUnusedE_genMC_fastpi";	
	TString acc_pi = "./baryonMid/etapi_looserUnusedE_accMC_fastpi";	
	TString sb_pi = "./baryonMid/etapi_looserUnusedE_sideband_fastpi";	

	FSCut::defineCut("etapi_bin0", "MASS(2,3)>2.0&&MASS(2,3)<2.1");
	FSCut::defineCut("mcetapi_bin0", "MCMASS(2,3)>2.0&&MCMASS(2,3)<2.1");

	FSCut::defineCut("etapi_bin1", "MASS(2,3)>2.1&&MASS(2,3)<2.2");
	FSCut::defineCut("mcetapi_bin1", "MCMASS(2,3)>2.1&&MCMASS(2,3)<2.2");

	FSCut::defineCut("etapi_bin2", "MASS(2,3)>2.2&&MASS(2,3)<2.3");
	FSCut::defineCut("mcetapi_bin2", "MCMASS(2,3)>2.2&&MCMASS(2,3)<2.3");

	FSCut::defineCut("etapi_bin3", "MASS(2,3)>2.3&&MASS(2,3)<2.4");
	FSCut::defineCut("mcetapi_bin3", "MCMASS(2,3)>2.3&&MCMASS(2,3)<2.4");

	FSCut::defineCut("etapi_bin4", "MASS(2,3)>2.4&&MASS(2,3)<2.5");
	FSCut::defineCut("mcetapi_bin4", "MCMASS(2,3)>2.4&&MCMASS(2,3)<2.5");

	FSCut::defineCut("etapi_bin5", "MASS(2,3)>2.5&&MASS(2,3)<2.6");
	FSCut::defineCut("mcetapi_bin5", "MCMASS(2,3)>2.5&&MCMASS(2,3)<2.6");

	FSCut::defineCut("etapi_bin6", "MASS(2,3)>2.6&&MASS(2,3)<2.7");
	FSCut::defineCut("mcetapi_bin6", "MCMASS(2,3)>2.6&&MCMASS(2,3)<2.7");

	FSCut::defineCut("etapi_bin7", "MASS(2,3)>2.7&&MASS(2,3)<2.8");
	FSCut::defineCut("mcetapi_bin7", "MCMASS(2,3)>2.7&&MCMASS(2,3)<2.8");

	FSCut::defineCut("etapi_bin8", "MASS(2,3)>2.8&&MASS(2,3)<2.9");
	FSCut::defineCut("mcetapi_bin8", "MCMASS(2,3)>2.8&&MCMASS(2,3)<2.9");
	

	FSModeTree::skimTree(acc_pi+".root","ntFSGlueX_101_1","",acc_pi+"_bin0.root","CUT(etapi_bin0)");
	FSModeTree::skimTree(acc_eta+".root","ntFSGlueX_101_1","",acc_eta+"_bin0.root","CUT(etapi_bin0)");

	FSModeTree::skimTree(sb_pi+".root","ntFSGlueX_101_1","",sb_pi+"_bin0.root","CUT(etapi_bin0)");
	FSModeTree::skimTree(sb_eta+".root","ntFSGlueX_101_1","",sb_eta+"_bin0.root","CUT(etapi_bin0)");

	FSModeTree::skimTree(sig_eta+".root","ntFSGlueX_101_1","",sig_eta+"_bin0.root","CUT(etapi_bin0)");
	FSModeTree::skimTree(sig_pi+".root","ntFSGlueX_101_1","",sig_pi+"_bin0.root","CUT(etapi_bin0)");

	FSModeTree::skimTree(gen_eta+".root","ntFSGlueX_101_1","",gen_eta+"_bin0.root","CUT(mcetapi_bin0)");
	FSModeTree::skimTree(gen_pi+".root","ntFSGlueX_101_1","",gen_pi+"_bin0.root","CUT(mcetapi_bin0)");



	FSModeTree::skimTree(acc_pi+".root","ntFSGlueX_101_1","",acc_pi+"_bin1.root","CUT(etapi_bin1)");
	FSModeTree::skimTree(acc_eta+".root","ntFSGlueX_101_1","",acc_eta+"_bin1.root","CUT(etapi_bin1)");

	FSModeTree::skimTree(sb_pi+".root","ntFSGlueX_101_1","",sb_pi+"_bin1.root","CUT(etapi_bin1)");
	FSModeTree::skimTree(sb_eta+".root","ntFSGlueX_101_1","",sb_eta+"_bin1.root","CUT(etapi_bin1)");

	FSModeTree::skimTree(sig_eta+".root","ntFSGlueX_101_1","",sig_eta+"_bin1.root","CUT(etapi_bin1)");
	FSModeTree::skimTree(sig_pi+".root","ntFSGlueX_101_1","",sig_pi+"_bin1.root","CUT(etapi_bin1)");

	FSModeTree::skimTree(gen_eta+".root","ntFSGlueX_101_1","",gen_eta+"_bin1.root","CUT(mcetapi_bin1)");
	FSModeTree::skimTree(gen_pi+".root","ntFSGlueX_101_1","",gen_pi+"_bin1.root","CUT(mcetapi_bin1)");


	FSModeTree::skimTree(acc_pi+".root","ntFSGlueX_101_1","",acc_pi+"_bin2.root","CUT(etapi_bin2)");
	FSModeTree::skimTree(acc_eta+".root","ntFSGlueX_101_1","",acc_eta+"_bin2.root","CUT(etapi_bin2)");

	FSModeTree::skimTree(sb_pi+".root","ntFSGlueX_101_1","",sb_pi+"_bin2.root","CUT(etapi_bin2)");
	FSModeTree::skimTree(sb_eta+".root","ntFSGlueX_101_1","",sb_eta+"_bin2.root","CUT(etapi_bin2)");

	FSModeTree::skimTree(sig_eta+".root","ntFSGlueX_101_1","",sig_eta+"_bin2.root","CUT(etapi_bin2)");
	FSModeTree::skimTree(sig_pi+".root","ntFSGlueX_101_1","",sig_pi+"_bin2.root","CUT(etapi_bin2)");

	FSModeTree::skimTree(gen_eta+".root","ntFSGlueX_101_1","",gen_eta+"_bin2.root","CUT(mcetapi_bin2)");
	FSModeTree::skimTree(gen_pi+".root","ntFSGlueX_101_1","",gen_pi+"_bin2.root","CUT(mcetapi_bin2)");


	FSModeTree::skimTree(acc_pi+".root","ntFSGlueX_101_1","",acc_pi+"_bin3.root","CUT(etapi_bin3)");
	FSModeTree::skimTree(acc_eta+".root","ntFSGlueX_101_1","",acc_eta+"_bin3.root","CUT(etapi_bin3)");

	FSModeTree::skimTree(sb_pi+".root","ntFSGlueX_101_1","",sb_pi+"_bin3.root","CUT(etapi_bin3)");
	FSModeTree::skimTree(sb_eta+".root","ntFSGlueX_101_1","",sb_eta+"_bin3.root","CUT(etapi_bin3)");

	FSModeTree::skimTree(sig_eta+".root","ntFSGlueX_101_1","",sig_eta+"_bin3.root","CUT(etapi_bin3)");
	FSModeTree::skimTree(sig_pi+".root","ntFSGlueX_101_1","",sig_pi+"_bin3.root","CUT(etapi_bin3)");

	FSModeTree::skimTree(gen_eta+".root","ntFSGlueX_101_1","",gen_eta+"_bin3.root","CUT(mcetapi_bin3)");
	FSModeTree::skimTree(gen_pi+".root","ntFSGlueX_101_1","",gen_pi+"_bin3.root","CUT(mcetapi_bin3)");


	FSModeTree::skimTree(acc_pi+".root","ntFSGlueX_101_1","",acc_pi+"_bin4.root","CUT(etapi_bin4)");
	FSModeTree::skimTree(acc_eta+".root","ntFSGlueX_101_1","",acc_eta+"_bin4.root","CUT(etapi_bin4)");

	FSModeTree::skimTree(sb_pi+".root","ntFSGlueX_101_1","",sb_pi+"_bin4.root","CUT(etapi_bin4)");
	FSModeTree::skimTree(sb_eta+".root","ntFSGlueX_101_1","",sb_eta+"_bin4.root","CUT(etapi_bin4)");

	FSModeTree::skimTree(sig_eta+".root","ntFSGlueX_101_1","",sig_eta+"_bin4.root","CUT(etapi_bin4)");
	FSModeTree::skimTree(sig_pi+".root","ntFSGlueX_101_1","",sig_pi+"_bin4.root","CUT(etapi_bin4)");

	FSModeTree::skimTree(gen_eta+".root","ntFSGlueX_101_1","",gen_eta+"_bin4.root","CUT(mcetapi_bin4)");
	FSModeTree::skimTree(gen_pi+".root","ntFSGlueX_101_1","",gen_pi+"_bin4.root","CUT(mcetapi_bin4)");



	FSModeTree::skimTree(acc_pi+".root","ntFSGlueX_101_1","",acc_pi+"_bin5.root","CUT(etapi_bin5)");
	FSModeTree::skimTree(acc_eta+".root","ntFSGlueX_101_1","",acc_eta+"_bin5.root","CUT(etapi_bin5)");

	FSModeTree::skimTree(sb_pi+".root","ntFSGlueX_101_1","",sb_pi+"_bin5.root","CUT(etapi_bin5)");
	FSModeTree::skimTree(sb_eta+".root","ntFSGlueX_101_1","",sb_eta+"_bin5.root","CUT(etapi_bin5)");

	FSModeTree::skimTree(sig_eta+".root","ntFSGlueX_101_1","",sig_eta+"_bin5.root","CUT(etapi_bin5)");
	FSModeTree::skimTree(sig_pi+".root","ntFSGlueX_101_1","",sig_pi+"_bin5.root","CUT(etapi_bin5)");

	FSModeTree::skimTree(gen_eta+".root","ntFSGlueX_101_1","",gen_eta+"_bin5.root","CUT(mcetapi_bin5)");
	FSModeTree::skimTree(gen_pi+".root","ntFSGlueX_101_1","",gen_pi+"_bin5.root","CUT(mcetapi_bin5)");


	FSModeTree::skimTree(acc_pi+".root","ntFSGlueX_101_1","",acc_pi+"_bin6.root","CUT(etapi_bin6)");
	FSModeTree::skimTree(acc_eta+".root","ntFSGlueX_101_1","",acc_eta+"_bin6.root","CUT(etapi_bin6)");

	FSModeTree::skimTree(sb_pi+".root","ntFSGlueX_101_1","",sb_pi+"_bin6.root","CUT(etapi_bin6)");
	FSModeTree::skimTree(sb_eta+".root","ntFSGlueX_101_1","",sb_eta+"_bin6.root","CUT(etapi_bin6)");

	FSModeTree::skimTree(sig_eta+".root","ntFSGlueX_101_1","",sig_eta+"_bin6.root","CUT(etapi_bin6)");
	FSModeTree::skimTree(sig_pi+".root","ntFSGlueX_101_1","",sig_pi+"_bin6.root","CUT(etapi_bin6)");

	FSModeTree::skimTree(gen_eta+".root","ntFSGlueX_101_1","",gen_eta+"_bin6.root","CUT(mcetapi_bin6)");
	FSModeTree::skimTree(gen_pi+".root","ntFSGlueX_101_1","",gen_pi+"_bin6.root","CUT(mcetapi_bin6)");


	FSModeTree::skimTree(acc_pi+".root","ntFSGlueX_101_1","",acc_pi+"_bin7.root","CUT(etapi_bin7)");
	FSModeTree::skimTree(acc_eta+".root","ntFSGlueX_101_1","",acc_eta+"_bin7.root","CUT(etapi_bin7)");

	FSModeTree::skimTree(sb_pi+".root","ntFSGlueX_101_1","",sb_pi+"_bin7.root","CUT(etapi_bin7)");
	FSModeTree::skimTree(sb_eta+".root","ntFSGlueX_101_1","",sb_eta+"_bin7.root","CUT(etapi_bin7)");

	FSModeTree::skimTree(sig_eta+".root","ntFSGlueX_101_1","",sig_eta+"_bin7.root","CUT(etapi_bin7)");
	FSModeTree::skimTree(sig_pi+".root","ntFSGlueX_101_1","",sig_pi+"_bin7.root","CUT(etapi_bin7)");

	FSModeTree::skimTree(gen_eta+".root","ntFSGlueX_101_1","",gen_eta+"_bin7.root","CUT(mcetapi_bin7)");
	FSModeTree::skimTree(gen_pi+".root","ntFSGlueX_101_1","",gen_pi+"_bin7.root","CUT(mcetapi_bin7)");


	FSModeTree::skimTree(acc_pi+".root","ntFSGlueX_101_1","",acc_pi+"_bin8.root","CUT(etapi_bin8)");
	FSModeTree::skimTree(acc_eta+".root","ntFSGlueX_101_1","",acc_eta+"_bin8.root","CUT(etapi_bin8)");

	FSModeTree::skimTree(sb_pi+".root","ntFSGlueX_101_1","",sb_pi+"_bin8.root","CUT(etapi_bin8)");
	FSModeTree::skimTree(sb_eta+".root","ntFSGlueX_101_1","",sb_eta+"_bin8.root","CUT(etapi_bin8)");

	FSModeTree::skimTree(sig_eta+".root","ntFSGlueX_101_1","",sig_eta+"_bin8.root","CUT(etapi_bin8)");
	FSModeTree::skimTree(sig_pi+".root","ntFSGlueX_101_1","",sig_pi+"_bin8.root","CUT(etapi_bin8)");

	FSModeTree::skimTree(gen_eta+".root","ntFSGlueX_101_1","",gen_eta+"_bin8.root","CUT(mcetapi_bin8)");
	FSModeTree::skimTree(gen_pi+".root","ntFSGlueX_101_1","",gen_pi+"_bin8.root","CUT(mcetapi_bin8)");
}
