#!/bin/bash -e

module load medgap/2.1
export TMP=$1
echo $TMP
shift
export LOGFILE=$1
echo $LOGFILE
shift

$*
