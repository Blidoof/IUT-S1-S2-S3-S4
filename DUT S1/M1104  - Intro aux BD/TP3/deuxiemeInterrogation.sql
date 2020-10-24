SELECT Competition.nom, type
FROM Competition JOIN Participer on Participer.numComp = Competition.numComp
JOIN Equipe on Participer.numEquipe = Equipe.numEquipe
WHERE Equipe.nom = 'Marseille';