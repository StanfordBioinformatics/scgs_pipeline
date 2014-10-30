#!/bin/bash -eu

echo "*** FASTQC ***"

if [ $# -lt 2 ]
then 
	echo "Usage: $0 outdir <bam>"
	exit 1
fi

outdir=`cd \`dirname $1\`; pwd`/`basename $1`
input=`cd \`dirname $2\`; pwd`/`basename $2`

command="fastqc -o $outdir $input"
	
echo ">>> FASTQC"
echo ">>> FASTQC" >> $LOGFILE
echo ">>> $command"
echo ">>> $command" >> $LOGFILE
$command

echo "*** Finished FASTQC ***"
