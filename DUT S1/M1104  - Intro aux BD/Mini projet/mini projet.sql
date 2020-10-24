
--GROUP BY (3)

	--1) Afficher la somme du nombre de selection par équipe

	SELECT equipe.nom, SUM(joueur.nbSelection)
	FROM joueur JOIN equipe ON equipe.numEquipe = joueur.numEquipe
	GROUP BY equipe.nom;

	--2) Afficher le nombre de joueurs par équipe

	SELECT numEquipe, COUNT(*)
	FROM joueur
	GROUP BY numEquipe;

	--3) Afficher la moyenne de selections par équipe

	SELECT equipe.nom, AVG(joueur.nbSelection)
	FROM joueur join equipe ON equipe.numEquipe = joueur.numEquipe
	GROUP BY equipe.nom;

--GROUP BY HAVING (3)

	--4) Afficher le nombre de selection des équipes dont la somme est supérieure à 20

	SELECT equipe.nom, SUM(joueur.nbSelection)
	FROM joueur join equipe ON equipe.numEquipe = joueur.numEquipe
	GROUP BY equipe.nom
	HAVING SUM(joueur.nbSelection) > 20;

	--5) Afficher le nom des équipes ayant plus de 5 joueurs

	SELECT equipe.nom, COUNT(*)
	FROM joueur JOIN equipe ON joueur.numEquipe = equipe.numEquipe
	GROUP BY equipe.nom
	HAVING COUNT(*) > 5;

	--6) Afficher les équipes dont la moyenne de selection est inférieure à 5

	SELECT equipe.nom, AVG(joueur.nbSelection)
	FROM joueur join equipe ON equipe.numEquipe = joueur.numEquipe
	GROUP BY equipe.nom HAVING AVG(joueur.nbSelection) < 5;

--ORDER BY (3)

	--1 zone de tri

		--7) Afficher la liste des équipe du + petit budget au + grand

		SELECT nom, budget
		FROM equipe
		ORDER BY budget;

		--8) Afficher la liste des joueurs (nom, prenom) ayant gagné la coupe de France (toutes saisons confondues) dans l'ordre ante-alphabétique

		SELECT joueur.nom, joueur.prenom
		FROM joueur JOIN gagnerJ ON gagnerJ.numJoueur = joueur.numJoueur 
		JOIN competition ON competition.numComp = gagnerJ.numComp
		WHERE competition.nom = 'CoupeFrance'
		ORDER BY joueur.nom DESC;

	--plusieurs zones de tri

		--9) Afficher les joueurs par ordre alphabétique puis par nombre de sélections

		SELECT nom, nbSelection
		FROM joueur
		ORDER BY nom, nbSelection;

--SELECT IMBRIQUES (6)

	--Requetes décorrélées

		--10) Afficher l'équipe au budget le plus grand

		SELECT nom, budget
		FROM equipe
		WHERE budget = (
			SELECT MAX(budget)
			FROM equipe );

		--11) Afficher les équipes à la capacité du stade supérieure à la moyenne de tout les stades

		SELECT nom, capaciteStade
		FROM equipe
		WHERE capaciteStade < (
			SELECT AVG(capaciteStade) 
			FROM equipe);

		
	--Jointures

		--12) Afficher la liste des joueurs, et leur nombre de selection, de l'équipe Soumoulou

		SELECT nom, prenom, nbSelection
		FROM Joueur
		WHERE numEquipe = (
			SELECT numEquipe
			FROM Equipe
			WHERE nom ='Soumoulou');

		--13) Palmarès (nom de la compétition gagnée et saison) de l'équipe 'Madrid' :

		SELECT  nom, saison
		FROM competition 
		WHERE numEquipe = (
			SELECT numEquipe
			FROM equipe
			WHERE equipe.nom = 'Madrid');

	--Jointure externe

		--14) Afficher le nom des joueurs n'ayant pas remporté la compétition 'Coupe de France' en 2017

		SELECT nom, prenom
		FROM joueur
		WHERE numJoueur NOT IN (
			SELECT numJoueur 
			FROM gagnerJ 
			WHERE numComp = 4);

	--Requête corrélée

		--15) Afficher les joueurs faisant partie d'une équipe dont la moyenne de sélection est inférieure à 5

		SELECT nom, prenom
		FROM joueur
		WHERE numEquipe IN (
			SELECT numEquipe
			FROM joueur GROUP BY numEquipe
			HAVING AVG(nbSelection) < 5);


