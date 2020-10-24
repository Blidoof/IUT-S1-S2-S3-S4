#!/bin/bash

BACKUPDIR=~/sauvegarde

# Test d'existence du fichier source
if [ ! -e $RESSOURCE ]; then
        echo "La ressource $RESSOURCE n'existe pas"
        exit 1
fi

# Ajout des droits d'écriture pour tout le monde
chmod -R +w $BACKUPDIR

fileok=false
while [[ $filename != 'end' ]]; do
	read -p "Entrez les ressources à sauvegarder ou \"end\" pour sortir : " filename

	# Test d'existence du fichier source
	if [ ! -e $filename ]; then
	    	echo "La ressource $filename n'existe pas"
	else
		## Test d'existence du fichier cible
		if [ -e $BACKUPDIR/$(basename $filename) ]; then
		    read -p "Le fichier $BACKUPDIR/$(basename $filename) existe déjà, veuillez entrer un autre nom pour la sauvegarde :" newfilename
		fi
		
		cp -a $filename $BACKUPDIR
		echo "Ressource $filename sauvegardé"
	fi
done

# SUppression des droits d'écriture pour tout le monde
chmod -R -w $BACKUPDIR

