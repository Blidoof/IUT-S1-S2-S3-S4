#!/bin/bash

clear

read -p "Entrez une note : " note

case $note in
[0-9]*) 

if [ $note -ge 16 ] && [ $note -le 20 ]; then
	echo "Très bien"
elif [ $note -ge 14 ] && [ $note -le 15 ]; then
	echo "Bien"
elif [ $note -ge 12 ] && [ $note -le 13 ]; then
	echo "Assez bien"
elif [ $note -ge 10 ] && [ $note -le 11 ]; then
	echo "Moyen"
elif [ $note -ge 0 ] && [ $note -lt 10 ]; then
	echo "Insuffisant"
else
	echo "La note $note n'est pas comprise entre 0 et 20"
	exit 1
fi
;;

*) echo "La chaîne saisie $note n'est pas numérique"
exit 1
;;
esac
exit 0
