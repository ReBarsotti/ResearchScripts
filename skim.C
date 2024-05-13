{
        TString NT("ntFSGlueX_101_1");

        FSModeCollection::addModeInfo("101_1")->addCategory("m101_1");

        // DEFINITION OF CUTS:
        FSCut::defineCut("unusedE","EnUnusedSh<0.1");
        FSCut::defineCut("unusedTracks","NumUnusedTracks<1");
        FSCut::defineCut("beamE","EnPB>8.1");
        FSCut::defineCut("chi2","Chi2DOF<5");
        FSCut::defineCut("mass23", "MASS(2,3)>1.8");

        FSCut::defineCut("xProton","ProdVx>=-1&&ProdVx<=1");
        FSCut::defineCut("yProton","ProdVy>=-1&&ProdVy<=1");
        FSCut::defineCut("zProton","ProdVz>=52&&ProdVz<=78");

        FSCut::defineCut("rf", "OR(abs(RFDeltaT)<2.0)");
        FSModeTree::createChi2RankingTree(INPUT,NT,"m101_1","CUT(rf,unusedE,unusedTracks,zProton,xProton,yProton)", "");

        FSTree::addFriendTree("Chi2Rank");

        FSCut::defineCut("chiRank","Chi2RankVar==Chi2RankVarBest");


        FSCut::defineCut("eta","abs(MASS([eta])-0.548)<0.05","(abs(MASS([eta])-0.548+0.105)<0.025 || abs(MASS([eta])-0.548-0.105)<0.025)", -0.5);
        FSCut::defineCut("pi0","abs(MASS([pi0])-0.135)<0.025","(abs(MASS([pi0])-0.135+0.04)<0.006 || abs(MASS([pi0])-0.135-0.04)<0.006)", -0.24);


        FSModeTree::skimTree(INPUT, NT, "", OUTPUT,"CUT(beamE,unusedE,unusedTracks,zProton,xProton, yProton,chi2,eta, pi0,chiRank)" );

        FSModeTree::skimTree(INPUT,NT,"",SBOUT, "CUT(beamE,unusedE,unusedTracks,xProton,yProton,zProton,chi2,chiRank) && CUTSBWT(eta,pi0)");


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


                if((abs(P2.M()-0.548+0.105)<0.025 || abs(P2.M()-0.548-0.105)<0.025) && (abs(P3.M()-0.135+0.04)<0.006 || abs(P3.M()-0.135-0.04)<0.006)){
                        weight = -0.12;
                }
                else if((abs(P2.M()-0.548+0.105)<0.025 || abs(P2.M()-0.548-0.105)<0.025)){
                        weight = 0.5;
                }
                else if((abs(P3.M()-0.135+0.04)<0.006 || abs(P3.M()-0.135-0.04)<0.006)){
                        weight = 0.24;
                }

                wt->Fill();
        }
        tr->Print();
        tr->Write();


}
