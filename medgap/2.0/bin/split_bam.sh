#!/bin/bash -eu

echo "*** Splitting BAM while preserving the RG tag ***"
echo "   " >> $LOGFILE

if [ $# -lt 1 ]
then 
	echo "Usage: $0 <bam>"
	exit 1
fi

module load bamtools

bam=`cd \`dirname $1\`; pwd`/`basename $1`
dir=`dirname $1`
stub=`basename $bam`

bam=$dir/$stub

echo "*** Splitting BAM while preserving the RG tag ***" >> $LOGFILE
command="bamtools split -in $bam -tag RG"
echo "$command" >> $LOGFILE
echo "$command"
$command

echo "*** Finished splitting BAM while preserving the RG tag ***"
