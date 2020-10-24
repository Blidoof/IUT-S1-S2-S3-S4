
--CREATION DES VUES

CREATE VIEW toutLesEtudiants
AS SELECT nom, prenom, anniversaire
   FROM Etudiant
   ORDER BY nom ASC;
   
CREATE VIEW effectifParDep (effectif, departement)
AS SELECT COUNT(*), departement
   FROM Etudiant
   GROUP BY departement;
   

CREATE VIEW effectifParNiveauEtGroupe (effectif, niveau, groupe)
AS SELECT COUNT (*), niveau, groupe
   FROM Etudiant
   GROUP BY niveau, groupe;

CREATE VIEW effectifGroupe (effectif, groupe)
AS SELECT COUNT(*), groupe
   FROM effectifParNiveauEtGroupe
   WHERE niveau = '1' 
   GROUP BY groupe;

CREATE VIEW pasMoyenne1Matiere
AS SELECT e.nom, e.prenom
   FROM Etudiant e JOIN MoyenneNotation n ON e.num = n.numEtud
   WHERE moyenne < 10;

CREATE VIEW etudiant2emeAnneeMoyenneSup12
AS SELECT nom, prenom
   FROM Etudiant e JOIN MoyenneNotation n ON e.num = n.numEtud
   WHERE n.moyenne >= 12 AND e.niveau = '2';

CREATE VIEW moyennePlus102AnneeAnglais (name, surname)
AS SELECT nom, prenom
   FROM etudiant2emeAnneeMoyenneSup12;


-- ATTRIBUTION DES VUES

GRANT INSERT, SELECT, DELETE, UPDATE
ON Etudiant
To xavellan;

GRANT SELECT 
ON toutLesEtudiants
TO xavellan;

GRANT SELECT 
ON effectifParDep
TO xavellan;

-- REQUETES A TESTER CHEZ XABI

SELECT nom, prenom
FROM xavellan_toutLesEtudiants;

DELETE FROM xavellan_toutLesEtudiants;

SELECT anniversaire
FROM xavellan_Etudiant;

DROP TABLE xavellan_Etudiant;