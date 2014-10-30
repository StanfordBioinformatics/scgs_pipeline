#!/bin/bash

set -e

if [ $# -lt 1 ]
then
        echo "Usage: $0 vcf variant_type"
        exit 1
fi

module load medgap/2.1

inVCF=`cd \`dirname $1\`; pwd`/`basename $1`
vtype=$2

Prefix=`dirname $inVCF`
Suffix=`basename $inVCF`
Sample=${Suffix/.vcf/}

vtypeVCF=$Prefix/$Ssample.$vtype.vcf

echo ">>> Select $vtype from $inVCF"

command="java -Xmx6g -Xms6g -jar $GATK/GenomeAnalysisTK.jar \
   -T SelectVariants \
   -R $REF \
   -V $inVCF \
   -o $vtypeVCF \
   -selectType $vtype"

echo ">>> $command"
$command
