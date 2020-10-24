--Liste des titres gagnés par l'équipe E : nom de l'équipe, 
--nom de la competition, type, année du titre
SELECT competition.nom, competition.type, competition.saison
FROM competition JOIN equipe ON competition.numEquipe = equipe.numEquipe
WHERE equipe.nom = 'Madrid';

--Liste des titres gagnés par le joueur J : nom, prenom
--nom de la competition, type, année du titre classé par ordre
-- ante chronologique
SELECT joueur.nom, joueur.prenom, competition.type, 
competition.nom, competition.saison
FROM joueur JOIN gagnerJ ON gagnerJ.numJoueur = joueur.numJoueur 
JOIN competition ON competition.numComp = gagnerJ.numComp
WHERE joueur.nom ='Deschamps';
ORDER BY competition.saison DESC;


--Liste des titres gagnés par les joueurs de l'équipe E :
-- nom des joueurs, prenom, nom compet, type, annee, par joueur
-- et dans l'ordre chronologique
SELECT joueur.nom, joueur.prenom, competition.type, 
competition.nom, competition.saison
FROM joueur 
JOIN equipe ON joueur.numEquipe = equipe.numEquipe
JOIN gagnerJ ON gagnerJ.numJoueur = joueur.numJoueur 
JOIN competition ON competition.numComp = gagnerJ.numComp
WHERE equipe.nom ='Marseille';
ORDER BY competition.saison;


--Liste des équipes ayant atteitn les 1/4 de finale de la compétiiton
--C triée dans l'ordre antéchronoligique
SELECT equipe.nom, competition.nom, competition.saison, participer.resultat
FROM equipe JOIN participer ON participer.numEquipe = equipe.numEquipe
JOIN competition ON competition.numComp = participer.numComp
WHERE competition.nom = 'CoupeFrance' AND participer.Resultat <= 5
ORDER BY competition.saison DESC;


--Liste des joueurs( nom, prenom) ayant gagné la compétition C
SELECT joueur.nom, joueur.prenom
FROM joueur JOIN gagnerJ ON gagnerJ.numJoueur = joueur.numJoueur 
JOIN competition ON competition.numComp = gagnerJ.numComp
WHERE competition.nom = 'CoupeFrance';

