#!/bin/bash -eu

echo "*** Strandomics coverage tool ***"

if [ $# -lt 2 ]
then 
	echo "Usage: $0 <bam>"
	exit 1
fi

input=`cd \`dirname $1\`; pwd`/`basename $1`

command="java -Xms5g -Xmx5g -jar $STRANDROOT/Analysis.jar coverage $input"
	
echo ">>> Strandomics coverage"
echo ">>> Strandomics coverage" >> $LOGFILE
echo ">>> $command"
echo ">>> $command" >> $LOGFILE
$command

mv *.cov $outdir

echo "*** Finished Strandomic coverage ***"
