#!/usr/bin/env python3
import subprocess
import sys
import argparse
import string

parser = argparse.ArgumentParser(description='Call sex of sample based on chrX heterozygous:total calls. Default PAR is based on GRch37: http://www.ncbi.nlm.nih.gov/assembly/GCF_000001405.13/') 
parser.add_argument('gzvcf', help='path to gzipped vcf to check' )
parser.add_argument('-m', '--malemax', help='chrX heterozygosity ratio less than or equal to this number will be called as male', default=0.3) 
parser.add_argument('-f', '--femalemin', help='chrX heterozygosity ratio greater than or equal to this number will be called as female', default=0.5) 
parser.add_argument('--par1start', help='start of pseudo-autosomal region, where calls will be ignored', default=60001)
parser.add_argument('--par1end', help='end of pseudo-autosomal region, where calls will be ignored', default=2699520)
parser.add_argument('--par2start', help='start of pseudo-autosomal region, where calls will be ignored', default=154931044)
parser.add_argument('--par2end', help='end of pseudo-autosomal region, where calls will be ignored', default=155260560)

args = parser.parse_args()

GTs = subprocess.check_output(['bcftools','query','-f\'[ %GT]\n\'','-r','chrX',args.gzvcf], universal_newlines = True)
total = 0
het = 0
hom = 0
GTs=GTs.splitlines()
for GT in GTs:
    GT = GT.lstrip('\' ')
    alleles = GT.split('/')
    if GT == '' or GT in string.whitespace:
        pass
    elif len(alleles) < 2 or '/' not in GT: 
        print('Unknown genotype: '+GT)
    elif alleles[0] == alleles[1]:
        hom = hom + 1 
        total = total + 1
    elif alleles[0] != alleles[1]:
        het = het + 1
        total = total + 1
    else:
        raise(Exception('Error parsing genotype: '+GT))
het_proportion = het/total
hom_proportion = hom/total
print('Total calls on chrX: '+str(total))
print('Het calls: '+str(het)+', '+str(het_proportion)+' of total')
print('Hom calls: '+str(hom)+', '+str(hom_proportion)+' of total')
if het_proportion <= args.malemax:
    print('Since the het propoprtion is less than {}, this sample is called as male.'.format(args.malemax))
elif het_proportion >= args.femalemin:
    print('Since the het proportion is greater than {}, this sample is called as female.'.format(args.femalemin))
else:
    print('Since the het proportion is between {} and {}, there is no call for this sample.'.format(args.malemax, args.femalemin))
