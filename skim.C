{
        TString NT("ntFSGlueX_101_1");

        FSModeCollection::addModeInfo("101_1")->addCategory("m101_1");

        // DEFINITION OF CUTS:
        FSCut::defineCut("unusedE","EnUnusedSh<0.1");
        FSCut::defineCut("unusedTracks","NumUnusedTracks<1");
        FSCut::defineCut("beamE","EnPB>8.1");
        FSCut::defineCut("chi2","Chi2DOF<5");
        FSCut::defineCut("mass23", "MASS(2,3)>1.8");

        FSCut::defineCut("xyProton","(VxP1*VxP1 + VyP1*VyP1)<=1");
        FSCut::defineCut("zProton","VzP1>=52&&VzP1<=78");

        FSCut::defineCut("rf", "(abs(RFDeltaT)<2.0)");
//      FSModeTree::createChi2RankingTree(INPUT,NT,"m101_1","CUT(rf,unusedE,unusedTracks)", "");

        FSTree::addFriendTree("Chi2Rank");

        FSCut::defineCut("chiRank","Chi2RankVar==Chi2RankVarBest");


        FSCut::defineCut("eta","abs(MASS([eta])-0.548)<(0.019*3)","(abs(MASS([eta])-0.548+(0.019*5.75))<(.019*1.25) || abs(MASS([eta])-0.548-(0.019*5.75))<(0.019*1.25))", -( 3.0 / 5.0));

//      FSCut::defineCut("eta","abs(MASS([eta])-0.548)<(0.019*4)","(abs(MASS([eta])-0.548+(0.019*6.25))<(.019*(1.75)) || abs(MASS([eta])-0.548-(0.019*6.25))<(0.019*1.75))", -( 4.0 / 7.0));

//      FSCut::defineCut("eta","abs(MASS([eta])-0.548)<(0.019*2)","(abs(MASS([eta])-0.548+(0.019*5.25))<(.019*(.75)) || abs(MASS([eta])-0.548-(0.019*5.25))<(0.019*.75))", -( 2.0 / 3.0));

// FSCut::defineCut("pi0","abs(MASS([pi0])-0.135)<(0.0076*3)","(abs(MASS([pi0])-0.135+(0.0076*5.))<(.0076*.5) || abs(MASS([pi0])-0.135-(0.0076*5.))<(.0076*.5))", -3.0/ 2.0);
//      FSCut::defineCut("pi0","abs(MASS([pi0])-0.135)<(0.0076*4)","(abs(MASS([pi0])-0.135+(0.0076*5.25))<(.0076*.75) || abs(MASS([pi0])-0.135-(0.0076*5.25))<(.0076*.75))", -4.0/ 3.0);

 FSCut::defineCut("pi0","abs(MASS([pi0])-0.135)<(0.0076*2)","(abs(MASS([pi0])-0.135+(0.0076*4.75))<(.0076*.25) || abs(MASS([pi0])-0.135-(0.0076*4.75))<(.0076*.25))", -2.0/ 1.0);

        FSModeTree::skimTree(INPUT, NT, "", OUTPUT,"CUT(beamE,unusedE,unusedTracks,zProton,xyProton,chi2,eta, pi0,chiRank)" );

        FSModeTree::skimTree(INPUT,NT,"",SBOUT, "CUT(beamE,unusedE,unusedTracks,xyProton,zProton,chi2,chiRank) && CUTSBWT(eta,pi0)");


        double PxP2,PyP2,PzP2,EnP2,PxP3,PyP3,PzP3,EnP3;

        double weight;
        TFile *file = new TFile(SBOUT,"update");
        TTree *tr = (TTree*) file->Get(NT);

        tr->SetBranchAddress("PxP2", &PxP2);
        tr->SetBranchAddress("PyP2", &PyP2);
        tr->SetBranchAddress("PzP2", &PzP2);
        tr->SetBranchAddress("EnP2", &EnP2);


        tr->SetBranchAddress("PxP3", &PxP3);
        tr->SetBranchAddress("PyP3", &PyP3);
        tr->SetBranchAddress("PzP3", &PzP3);
        tr->SetBranchAddress("EnP3", &EnP3);

        TBranch *wt = tr->Branch("weight", &weight, "weight/D");

        int numEvent = tr->GetEntries();

        for(int i=0;i<numEvent;i++){
                tr->GetEntry(i);
                TLorentzVector P2(PxP2,PyP2,PzP2,EnP2);
                TLorentzVector P3(PxP3,PyP3,PzP3,EnP3);


                if((abs(P2.M()-0.548+(0.019*5.75))<(.019*1.25) || abs(P2.M()-0.548-(0.019*5.75))<(.019*1.25)) && (abs(P3.M()-0.135+(0.0076*4.75))<(0.0076*0.25) || abs(P3.M()-0.135-(0.0076*4.75))<(0.0076*.25))){
                        weight = - 6.0 / (1.0* 5.0);
                }
                else if((abs(P2.M()-0.548+(0.019*5.75))<(.019*1.25) || abs(P2.M()-0.548-(0.019*5.75))<(.019*1.25))){
                        weight = 3.0 / 5.0;
                }
                else if((abs(P3.M()-0.135+(0.0076*4.75))<(.0076*.25) || abs(P3.M()-0.135-(0.0076*4.75))<(.0076*.25))){
                        weight = 2.0 / 1.0;
                }

                wt->Fill();
        }
        tr->Print();
        tr->Write();


}
