# ResearchScripts
Starting with an eta pi0 analysis tree
1. Flatten -- This requires FlattenForFSRoot if it is for accepted MC use runFlattenMC.pl, if generated/thrown MC use runFlattenThrown.pl, if it data then runFlatten.pl
2. Skim for Eta Pi0 reaction -- runSkim.pl will call the skim.C macro
3. Skim for Double Regge region -- skimDblRegge.C selects for the defined region of double Regge phasespace
