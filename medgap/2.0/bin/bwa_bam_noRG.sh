#!/bin/bash -eu

echo "*** Aligning reads using BWA MEM algorithm ***"
echo "*** Aligning reads using BWA MEM algorithm ***" >> $LOGFILE

if [ $# -lt 1 ]
then 
	echo "Usage: $0 <fastq1> <fastq2> [num of threads] [RG tag]  or $0 <bam> [num of threads] [RG tag]"
	exit 1
fi


bam=`cd \`dirname $1\`; pwd`/`basename $1`
cores=$2
PL=$3
LB=$4
SM=$5
ID=$6

echo ">> BAM input"
echo ">> BAM input" >> $LOGFILE
command="samtools bam2fq $bam | bwa mem -CMp -t $cores -R \"@RG\tID:$ID\tLB:$LB\tPL:$PL\tSM:$SM\" $REF - | samtools view -Sbt $REF.fai -o ${bam/.bam/}.bwa.bam -"
samtools bam2fq $bam | bwa mem -CMp -t $cores -R "@RG\tID:Default\tLB:Library\tPL:Illumina\tSM:SAMPLE" $REF - | samtools view -Sbt $REF.fai -o ${bam/.bam/}.bwa.bam -
echo ">>> $command"
echo ">>> $command" >> $LOGFILE

echo "*** Finished aligning reads ***"
