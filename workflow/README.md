# ResearchScripts
**Starting with an eta pi0 analysis tree**
1. Flatten -- This requires FlattenForFSRoot if it is for accepted MC use runFlattenMC.pl, if generated/thrown MC use runFlattenThrown.pl, if it data then runFlatten.pl
2. Skim for Eta Pi0 reaction -- runSkim.pl will call the skim.C macro
3. Skim for Double Regge region -- skimDblRegge.C selects for the defined region of double Regge phasespace
4. Skim into eta pi0 mass bins -- binSkimDblRegge.C skims the files into eta pi mass bins for fitting
5. fit_TEMPLATE.cfg is the template for fit configuration files to be created and then fit with amptools
6. genCFG.pl is used to create config files from the template
7. driveFit.pl is used to actually run the fits
8. asymmetry.C will compute the asymmetry of a fit result

**uncertainty codes**
- statErr.C is used to compute the statistical uncertainties. The bootstrap uncertainties are pre-computed.

**Plotting codes**
- plotYield.C is used to plot the yields of the different components with pre-computed statistical uncertainties
- fullErrorAsym.C is used to plot the asymmetry "money" plot using pre-computed statistical and systematic uncertainties
- ninepanel.C and genninepanel.C will produce the fit result plots show in my thesis appendix (ninepanel is the green accMC and data plots, genninepanel is the yellow genMC). The root files needed for these plotting codes can be produced using the plotResults executble
