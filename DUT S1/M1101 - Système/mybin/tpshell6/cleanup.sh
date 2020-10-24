#! /bin/bash

archive_dir=$(date +"%Y%m%d")
backup_dir="sauvegarde"

rm Gros_fichier.*
rm script.sh.*
mv $archive_dir/* $backup_dir
rmdir $archive_dir
