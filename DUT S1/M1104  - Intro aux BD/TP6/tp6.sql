--Modifier table competition -- Done
ALTER TABLE COMPETITION
ADD (saison NUMBER(4), numEquipe NUMBER(3), 
FOREIGN KEY (numEquipe) REFERENCES Equipe(numEquipe));

--Insérer saisons
UPDATE COMPETITION
SET saison = 2016;


--Palamares joueur -- Done
CREATE TABLE GAGNERJ (
numJoueur NUMBER(3),
numComp NUMBER(3),
PRIMARY KEY (numJoueur,numComp),
FOREIGN KEY (numComp)
REFERENCES Competition (numComp),
FOREIGN KEY (numJoueur)
REFERENCES Joueur (numJoueur)
);

--Peuplement GAGNERE
INSERT INTO Competition
VALUES (
4,'CoupeFrance','Coupe', 2017, 3);

INSERT INTO Competition
VALUES (
5,'LigueDesChampions','Championnat', 2017, 2);

INSERT INTO Competition
VALUES (
6,'Championnat regional','Championnat', 2017, 5);

INSERT INTO Competition
VALUES (
7,'CoupeFrance','Coupe', 2018, 1);

INSERT INTO Competition
VALUES (
8,'LigueDesChampions','Championnat', 2018, 2);

INSERT INTO Competition
VALUES (
9,'Championnat regional','Championnat', 2018, 4);

--Peuplement GAGNERJ
INSERT INTO GagnerJ
VALUES (
1,7
);

INSERT INTO GagnerJ
VALUES (
4,8
);

INSERT INTO GagnerJ
VALUES (
5,5
);

INSERT INTO GagnerJ
VALUES (
11,9
);

INSERT INTO GagnerJ
VALUES (
12,9
);


INSERT INTO GagnerJ
VALUES (
24,6
);

INSERT INTO GagnerJ
VALUES (
23,6
);

INSERT INTO GagnerJ
VALUES (
16,8
);

INSERT INTO GagnerJ
VALUES (
18,4
);

INSERT INTO GagnerJ
VALUES (
17,4
);

