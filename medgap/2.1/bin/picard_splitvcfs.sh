#!/bin/bash -eu

echo "*** Splitting VCFs into indel and snp ***"

if [ $# -lt 2 ]
then 
	echo "Usage: $0 vcf snp.vcf indel.vcf"
	exit 1
fi

module load medgap
inVCF=`cd \`dirname $1\`; pwd`/`basename $1`
snpVCF=`cd \`dirname $2\`; pwd`/`basename $2`
indelVCF=`cd \`dirname $3\`; pwd`/`basename $3`

command="java -Xms5g -Xmx5g -jar /srv/gs1/software/picard-tools/1.92/SplitVcfs.jar \
	INPUT=$inVCF \
	SNP_OUTPUT=$snpVCF \
	INDEL_OUTPUT=$indelVCF \
	SEQUENCE_DICTIONARY=$REF \
	VALIDATION_STRINGENCY=SILENT"

echo ">>> $command"
$command

