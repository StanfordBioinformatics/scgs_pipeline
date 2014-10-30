#!/bin/bash

echo ">>> Executing VQSR R scripts"
echo "   " >> $LOGFILE
echo ">>> Executing VQSR R Scripts" >> $LOGFILE

set -e

if [ $# -lt 1 ]
then
        echo "Usage: $0 <vcf>"
        exit 1
fi

module load r/3.1.0

f=''
for i in $*
do
	command="Rscript $i"
	echo ">>> $command" >> $LOGFILE
	$command 
done

echo ">>> Finished VQSR R Scripts"
