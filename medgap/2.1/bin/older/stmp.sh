#!/bin/bash -eu

echo "*** STMP (STANOVAR) ***"

if [ $# -lt 2 ]
then 
	echo "Usage: $0 outdir <vcf> cores"
	exit 1
fi

outdir=`cd \`dirname $1\`; pwd`/`basename $1`
input=`cd \`dirname $2\`; pwd`/`basename $2`
cores=$3

command="python $STMP_HOME/bin/stmp.py -v $input -o $outdir -n $cores -s /srv/gs1/software/stmp/stmp-0.1/bin/resource/sfs/AllVarsALL-SFspectrum12.txt"
	
echo ">>> STMP (STANOVAR)"
echo ">>> STANOVAR" >> $LOGFILE
echo ">>> $command"
echo ">>> $command" >> $LOGFILE
$command

echo "*** Finished STMP (STANOVAR) ***"
