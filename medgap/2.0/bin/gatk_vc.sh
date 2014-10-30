#!/bin/bash -eu

echo "*** Performing SNV discovery and genotyipng using GATK ***"
echo "   " >> $LOGFILE
echo "*** Performing SNV discovery and genotyipng using GATK ***" >> $LOGFILE

if [ $# -lt 4 ]
then 
	echo "Usage: $0 output snp_hapcaller indel_hapcaller bam ..."
	exit 1
fi

o=`cd \`dirname $1\`; pwd`/`basename $1`
shift
output_hc=$o.hc.vcf
output_gc=$o.gc.vcf

snp_vcf=$o.snp
indel_vcf=$o.indel

snp_hap=$1
shift
indel_hap=$1
shift

optL=''
if [ $# -eq 1 ]
then
	echo $1
        if [[ "$1" =~ *chr[^\.]*\..* ]]
        #if [[ "$1" =~ ".*chr[^.]*\..*" ]]
        then
		echo "here"
                chr=`echo "$1" | sed 's/.*\(chr[^\.]*\)\..*/\1/'`
                optL="-L $chr"
        fi
fi

f=''
for i in $*
do
        f="$f -I `cd \`dirname $i\`; pwd`/`basename $i`"
done

log=${o/gatk.vcf/}vc.log

run_hc="False"
run_gc="False"
if [[ "$snp_hap" == "True" ]] || [[ "$indel_hap" == "True" ]] 
then
	run_hc="True"
fi

if [[ "$snp_hap" != "True" ]] || [[ "$indel_hap" != "True" ]] 
then
	run_gc="True"
fi

gc_command="java -Xmx8g -Xms8g -Djava.io.tmpdir=$TMP -jar $GATK/GenomeAnalysisTK.jar \
   -T UnifiedGenotyper \
   -R $REF \
   $f \
   --dbsnp $DBSNP \
   -o $output_gc $optL \
   -stand_call_conf 20.0 \
   -stand_emit_conf 10.0 \
   -gt_mode DISCOVERY \
   --genotype_likelihoods_model BOTH \
   --output_mode EMIT_ALL_SITES \
   -nct 4"

hc_command="java -Xmx8g -Xms8g -Djava.io.tmpdir=$TMP -jar $GATK/GenomeAnalysisTK.jar \
     -T HaplotypeCaller \
     -R $REF \
     $f \
     --dbsnp $DBSNP \
     -o $output_hc $optL \
     -stand_call_conf 20.0 \
     -stand_emit_conf 10.0 \
     --genotyping_mode DISCOVERY \
     -nct 4"

     #-pairHMM VECTOR_LOGLESS_CACHING \
     #-ERC BP_RESOLUTION \
# https://gatkforums.broadinstitute.org/discussion/3115/emit-all-sites-in-haplotypecaller
# http://www.broadinstitute.org/gatk/gatkdocs/org_broadinstitute_sting_gatk_walkers_haplotypecaller_HaplotypeCaller.html

if [[ "$run_gc" == "True" ]]
then
	echo ">>> Running the GATK's UnifiedGenotyper"
	echo ">>> Running the GATK's UnifiedGenotyper" >> $LOGFILE
	echo ">>> $gc_command"
	echo ">>> $gc_command" >> $LOGFILE
	$gc_command &> $log 
fi

if [[ "$run_hc" == "True" ]]
then
	echo ">>> Running the GATK's Haplotyper"
	echo ">>> Running the GATK's Haplotyper" >> $LOGFILE
	echo ">>> $hc_command"
	echo ">>> $hc_command" >> $LOGFILE
	$hc_command &> $log
fi

if [[ "$snp_hap" == "True" ]] && [[ "$indel_hap" == "True" ]]
then
	# select both snps and indels from HC
	select_indel_from=$output_hc
	select_snp_from=$output_hc
fi

if [[ "$snp_hap" == "True" ]] && [[ "$indel_hap" != "True" ]]
then
	# select snps from HC and indels from GC
	select_indel_from=$output_gc
	select_snp_from=$output_hc
fi
if [[ "$snp_hap" != "True" ]] && [[ "$indel_hap" == "True" ]]
then
	# select snps from GC and indels from HC
	select_indel_from=$output_hc
	select_snp_from=$output_gc
fi
if [[ "$snp_hap" != "True" ]] && [[ "$indel_hap" != "True" ]]
then
	# select snps and indels from GC
	select_indel_from=$output_gc
	select_snp_from=$output_gc
fi

command="java -Xmx8g -Xms8g -jar $GATK/GenomeAnalysisTK.jar \
	-T SelectVariants \
	-R $REF \
	-V $select_snp_from \
	-o $snp_vcf \
	-selectType SNP"

	echo ">>> Selecting SNPs from $select_snp_from"
	echo ">>> Selecting SNPs from $select_snp_from" >> $LOGFILE
	echo ">>> $command"
	echo ">>> $command" >> $LOGFILE
	$command &> $log

command="java -Xmx8g -Xms8g -jar $GATK/GenomeAnalysisTK.jar \
	-T SelectVariants \
	-R $REF \
	-V $select_indel_from \
	-o $indel_vcf \
	-selectType INDEL"

	echo ">>> Selecting Indels from $select_indel_from"
	echo ">>> Selecting Indels from $select_indel_from" >> $LOGFILE
	echo ">>> $command"
	echo ">>> $command" >> $LOGFILE
	$command &> $log

command="java -Xmx8g -Xms8g -jar $GATK/GenomeAnalysisTK.jar \
	-R $REF \
	-T CombineVariants \
	--variant $snp_vcf \
	--variant $indel_vcf \
	-o $o"

	echo ">>> Combining SNP and Indel VCFs"
	echo ">>> Combining SNP and Indel VCFs" >> $LOGFILE
	echo ">>> $command"
	echo ">>> $command" >> $LOGFILE
	$command &> $log

echo "*** Finished SNV discovery and genotyipng using GATK ***"

