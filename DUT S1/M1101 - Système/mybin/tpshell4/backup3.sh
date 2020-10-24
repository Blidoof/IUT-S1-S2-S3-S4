#!/bin/bash

BACKUPDIR=~/sauvegarde
RESSOURCE=$1

echo "Ressource : $RESSOURCE"

# Test d'existence du fichier source
if [ ! -e $RESSOURCE ]; then
	echo "La ressource $RESSOURCE n'existe pas"
	exit 1
fi

chmod -R +w $BACKUPDIR

## Test d'existence du fichier cible
if [ -e $BACKUPDIR/$(basename $RESSOURCE) ]; then
	newfilename=$(basename $RESSOURCE)
else
	inc=$(echo $(basename $RESSOURCE)#1 | grep -o -E "#[0-9]+$" |grep -o -E "[0-9]+$")
	inc=$(( $inc+1 ))
	newfilename=$(basename $RESSOURCE)#$inc
fi

cp -a $RESSOURCE $BACKUPDIR/$newfilename

if [ $? -eq 0 ];then
	echo "Ressource $RESSOURCE sauvegardé sous le nom $newfilename"
else
	echo "Problème à la copie de la ressource $RESSOURCE vers $newfilename"
	exit 1
fi

# Suppression des droits d'écriture pour tout le monde
chmod -R -w $BACKUPDIR

exit 0
