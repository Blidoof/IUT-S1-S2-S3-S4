SELECT Joueur.nom, prenom
FROM Joueur JOIN Equipe ON Equipe.numEquipe = Joueur.numEquipe
WHERE Equipe.nom ='Marseille';