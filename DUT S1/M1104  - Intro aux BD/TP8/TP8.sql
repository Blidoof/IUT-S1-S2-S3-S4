--1.1 Nom de l'équipe au stade le plus petit

SELECT nom
FROM equipe
WHERE capaciteStade =(
	SELECT MIN(capaciteStade) 
	FROM equipe);

--1.2 Nom des équipes au budget > à la moyenne des budgets

SELECT nom
FROM equipe
WHERE budget >(
	SELECT AVG(budget) 
	FROM equipe );

--1.3 Nom des équipes au budget < à ceux des équipes E1,E2,E3

SELECT nom
FROM equipe
WHERE budget < ALL(
	SELECT budget 
	FROM equipe 
	WHERE nom IN('Soumoulou','Marseille','Bayonne'));

--1.4 Nom des joueurs ayant un nb de selections > à au moins
--un des joueurs de l'équipe E 

SELECT nom
FROM joueur
WHERE nbSelection > ANY(
	SELECT joueur.nbSelection
	FROM joueur
	WHERE numEquipe =(
		SELECT numEquipe
		FROM equipe
		WHERE nom ='Marseille'));

--2.1 Nom des joueurs de l'équipe E1

SELECT nom
FROM joueur
WHERE numEquipe =(
	SELECT numEquipe 
	FROM equipe 
	WHERE nom='Marseille');

--2.2 Nom des joueurs ayant remporté la competition C1

SELECT nom
FROM joueur
WHERE numJoueur = ANY(
	SELECT numJoueur 
	FROM gagnerJ
	WHERE numComp = ANY(
		SELECT numComp
		FROM competition
		WHERE nom ='CoupeFrance'));

--3.1 Nom des equipes n'ayant pas gagné la competition C1

SELECT nom
FROM equipe
WHERE numEquipe NOT IN (	
    SELECT numEquipe
    FROM COMPETITION
    WHERE nom='CoupeFrance') ;

--3.2 Nom des equipes n'ayant gagné aucun titre

SELECT nom
FROM equipe
WHERE NOT EXISTS (
	SELECT numEquipe
	FROM competition
	WHERE equipe.numEquipe = competition.numEquipe);



--3.3 Nom des joueurs n'ayant pas gagné la competition C1

SELECT nom, prenom
FROM JOUEUR
WHERE num NOT IN ( 
    SELECT numJoueur
    FROM COMPETITION
    JOIN gagnerJ
    ON gagnerJ.numComp=competition.numComp
    WHERE nom='CoupeFrance') ;

--3.4 Nom des joueurs n'ayant gagné aucun titre

SELECT DISTINCT joueur.nom
FROM joueur JOIN gagnerJ ON gagnerJ.numJoueur = joueur.numJoueur
WHERE joueur.numJoueur NOT IN(
		SELECT numJoueur
		FROM gagnerJ);

--3.5 Nom des equipes n'ayant pas gagné des competitions de type coupe

--3.6 Nom des joueurs n'ayant pas gagné des competitions de type coupe

--4.1 Nom des joueurs qui ont le plus petit nombre de selection dans leur équipe

--4.2 Nom des équipes qui ont un stade dont la capacité est différente des autres

