#!/bin/bash
filesdir=$1
searchstr=$2
if [ -z "$filesdir" ] || [ -z "$searchstr" ]; then
	echo "the parameters above were not specified"
	exit 1
fi
if [ ! -d "$filesdir" ]; then
	echo "filesdir does not represent a directory on the filesystem"
	exit 1
fi
X=$(find "$filesdir" -type f | wc -l)
Y=$(grep -r "$searchstr" "$filesdir" 2>/dev/null | wc -l)

echo "The number of files are $X and the number of matching lines are $Y"
