#!/bin/bash -eu

echo "*** Merging BAMs ***"

if [ $# -lt 2 ]
then 
	echo "Usage: $0 <outbam> <inbam>..."
	exit 1
fi

output=$1
shift

input=`cd \`dirname $1\`; pwd`/`basename $1`
shift
for i in $*
do
        input="$input INPUT=`cd \`dirname $i\`; pwd`/`basename $i`"
done

command="java -Xms8g -Xmx8g -jar $PICARD/MergeSamFiles.jar \
	TMP_DIR=$TMP \
	INPUT=$input \
	USE_THREADING=true \
	CREATE_INDEX=true \
	OUTPUT=$output" 
	
echo ">>> Merging BAMs" >> $LOGFILE
echo ">>> $command"
echo ">>> $command" >> $LOGFILE
$command

echo "*** Finished mergine BAMs ***"
