#!/bin/bash

export SCRAM_ARCH=slc5_amd64_gcc462

cd /afs/cern.ch/user/p/peruzzi/work/minitree_600pre4/CMSSW_6_0_0_pre4/src/SinglePhoton/PhotonPUAnalyzer/test || exit 1

eval `scram runtime -sh`

DIRNAME=`basename $1 .root`

mkdir $DIRNAME

cd $DIRNAME || exit 1

cmsRun ../eleAF600pre2_cfg.py files=$1

mv outfile.root ../output_600pre2/outfile_${DIRNAME}.root
cd ..
rmdir $DIRNAME

