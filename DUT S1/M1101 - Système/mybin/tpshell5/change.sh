#!/bin/bash

if [ ! -e "$1" ]; then
    echo "Fichier $1 introuvable"
    exit 0
fi

echo "Dernière date de modification : "; date -r $1
touch $1 
echo "Nouvelle dernière date de modification : "; date -r $1

exit 0
