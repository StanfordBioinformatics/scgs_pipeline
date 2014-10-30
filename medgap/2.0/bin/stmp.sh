#!/bin/bash -eu

echo "*** STMP (STANOVAR) ***"

if [ $# -lt 2 ]
then 
	echo "Usage: $0 outdir <vcf> cores"
	exit 1
fi

outdir=`cd \`dirname $1\`; pwd`/`basename $1`
baminput=`cd \`dirname $2\`; pwd`/`basename $2`
input=`cd \`dirname $3\`; pwd`/`basename $3`
cores=$4

command="python $STMP_HOME/bin/stmp.py -b $baminput -v $input -o $outdir -n $cores -s $STMP_HOME/bin/resource/sfs/AllVarsALL-SFspectrum12.txt"
	
echo ">>> STMP (STANOVAR)"
echo ">>> STANOVAR" >> $LOGFILE
echo ">>> $command"
echo ">>> $command" >> $LOGFILE
$command

echo "*** Finished STMP (STANOVAR) ***"
