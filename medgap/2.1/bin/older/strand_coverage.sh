#!/bin/bash -eu

echo "*** Strandomics coverage tool ***"

if [ $# -lt 2 ]
then 
	echo "Usage: $0 <bam>"
	exit 1
fi

outdir=`cd \`dirname $1\`; pwd`/`basename $1`
input=`cd \`dirname $2\`; pwd`/`basename $2`
indir=`dirname $2`

command="java -Xms5g -Xmx5g -jar $STRANDROOT/Analysis.jar coverage $input"
	
echo ">>> Strandomics coverage"
echo ">>> Strandomics coverage" >> $LOGFILE
echo ">>> $command"
echo ">>> $command" >> $LOGFILE
$command

mv $indir/*.cov $outdir

echo "*** Finished Strandomic coverage ***"
