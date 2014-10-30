#!/bin/bash

echo ">>> Running Kwality"
echo "   " >> $LOGFILE
echo ">>> Running Kwality" >> $LOGFILE

set -e

if [ $# -lt 1 ]
then
        echo "Usage: $0 <vcf>"
        exit 1
fi

outdir=$1
bam=$2
vcf=$3

module load kwality

command="kwality.py -c /srv/gsfs0/projects/gbsc/Clinical_Service/tools/qc/qc-1.0.json -s outdir/qc.sjm bam=$bam vcf=$vcf --outdir $outdir"
echo ">>> $command"
echo ">>> $command" >> $LOGFILE
exit
$command 

echo ">>> Finished Kwality"
