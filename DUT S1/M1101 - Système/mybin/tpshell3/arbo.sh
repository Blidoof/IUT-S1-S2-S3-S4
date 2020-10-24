#!/bin/bash

if [ -z $1 ]; then
	echo "Pas de nom de répertoire passé en paramètre"
   	exit 1
else
	ARG=$1
fi

mkdir $ARG
for i in $( seq 1 10 ); do
	echo "création de $ARG/$ARG$i"
	touch $ARG/$ARG$i 
done

exit 0
