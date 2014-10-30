#!/bin/bash -eu

echo "*** FLAGSTAT ***"

if [ $# -lt 2 ]
then 
	echo "Usage: $0 outdir <bam>"
	exit 1
fi

outdir=`cd \`dirname $1\`; pwd`/`basename $1`
input=`cd \`dirname $2\`; pwd`/`basename $2`

command="samtools flagstat $input > $outdir/$input.stat"
	
echo ">>> FLAGSTAT"
echo ">>> FLAGSTAT" >> $LOGFILE
echo ">>> $command"
echo ">>> $command" >> $LOGFILE
$command

echo "*** Finished FLAGSTAT ***"
