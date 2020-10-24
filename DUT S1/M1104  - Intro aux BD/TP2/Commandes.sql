-- TP 2

-- Modifier le schéma de ETUDIANT en ajoutant : année, parcours

ALTER TABLE Etudiant
ADD (
annee NUMBER (1),
parcours VARCHAR (3));

-- mettre a jour attribut annee ( 1 pour tout les n-uplets )

UPDATE Etudiant
SET annee = 1;

--Supprimer etudiants TP5

DELETE FROM Etudiant
WHERE groupeTP = 5;

--Modifier Etudiant en supprimant Parcours

ALTER TABLE Etudiant
DROP (parcours);

--Modifier l'attribut prenom dans Eudiant

ALTER TABLE Etudiant
MODIFY (prenom VARCHAR (35));

-- Supprimer la table Etudiant

DROP TABLE Etudiant;
