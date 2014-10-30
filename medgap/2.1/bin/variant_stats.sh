#!/bin/bash

echo ">>> Counting variants in final TSV file"
echo "   " >> $LOGFILE
echo ">>> Counting variants in final TSV file" >> $LOGFILE

set -e

if [ $# -lt 1 ]
then
        echo "Usage: $0 <vcf>"
        exit 1
fi

stat=$1
tsv=$2

command="/srv/gsfs0/projects/gbsc/Clinical_Service/tools/stmp/parse_tsv.pl $stat $tsv"
echo ">>> $command" >> $LOGFILE
echo ">>> $command"
exit
$command 

echo ">>> Finished Counting variants in final TSV file"
