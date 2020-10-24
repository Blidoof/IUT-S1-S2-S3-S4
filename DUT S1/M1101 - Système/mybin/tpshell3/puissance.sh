#!/bin/bash

clear

read -p "Veuillez entrer un nombre : " nombre

puissance=1
#for i in ̀ seq 1 $nombre ̀ ; do
#for i in $( seq 1 $nombre ); do
for (( i=1; $i<=$nombre; i++ )); do
	echo "Seq : $i, calcul $puissance * $nombre "
	puissance=$(( $puissance * $nombre ))
done
echo $nombre'^'$nombre' = '$puissance
