-- afficher capcité stade le plus petit
SELECT MIN(capaciteStade)
FROM EQUIPE;
--Resultat : 2000

--Afficher le budget le important
SELECT MAX(budget)
FROM EQUIPE;
--Resultat : 900000

--Afficher liste des joueurs trié par ordre alphabetique
SELECT nom, prenom
FROM JOUEUR
ORDER BY nom;

--Afficher la liste des équipes (nom, capacité) triée par capacité de stade décroissante
SELECT nom, capaciteStade
FROM EQUIPE
ORDER BY capaciteStade DESC;

--Afficher le nombre de joueurs par équipe
SELECT numEquipe, COUNT(*)
FROM JOUEUR
GROUP BY numEquipe;

--Afficher la liste des equipes encore qualifiées pour la competition 1
SELECT EQUIPE.nom
FROM EQUIPE JOIN PARTICIPER ON EQUIPE.numEquipe = PARTICIPER.numEquipe
JOIN COMPETITION ON COMPETITION.numComp = PARTICIPER.numComp
WHERE COMPETITION.nom = 'CoupeFrance' AND PARTICIPER.resultat=0;
--Resultat : Soumoulou

--Afficher le classement de la competition
SELECT EQUIPE.nom, PARTICIPER.resultat
FROM EQUIPE JOIN PARTICIPER ON EQUIPE.numEquipe = PARTICIPER.numEquipe
JOIN COMPETITION ON COMPETITION.numComp = PARTICIPER.numComp
WHERE COMPETITION.nom = 'LigueDesChampions' 
ORDER BY resultat DESC;

--Afficher la liste des joueurs avec plusieurs homonymes
SELECT nom
FROM JOUEUR
GROUP BY nom HAVING COUNT(*)>1;
--Resultat : HAZARD


--Afficher le nom de l'Equipe au stade le plus petuit
SELECT nom
FROM EQUIPE
WHERE capaciteStade = (SELECT MIN(capaciteStade) FROM EQUIPE);
--resultat : BAYONNE

--Afficher l'équipe au budget le + important
SELECT nom
FROM EQUIPE
WHERE budget = (SELECT MAX(budget) FROM EQUIPE);
--Resultat : BAYONNE