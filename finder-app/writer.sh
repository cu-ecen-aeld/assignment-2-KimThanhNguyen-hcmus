#!/bin/sh
writefile=$1
writestr=$2
if [ -z "$writefile" ] || [ -z "$writestr" ]; then
	echo "the arguments above were not specified"
	exit 1
fi

mkdir -p "$(dirname "$writefile")"

if ! echo "$writestr" > "$writefile"; then
	echo "the file could not be created"
	exit 1
fi
