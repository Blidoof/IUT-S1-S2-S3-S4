--1

CREATE OR REPLACE TYPE Lien AS OBJECT (
Uris VARCHAR2(50),
Relations VARCHAR2(50)
);

CREATE TYPE liens AS TABLE OF Lien;

CREATE TYPE GEO AS OBJECT (
x NUMBER (30,30),
y NUMBER (30,30)
);

CREATE TYPE Metadonnee AS OBJECT(
Au VARCHAR2(50),
Geo GEO,
D VARCHAR2(50)
);



CREATE TABLE RO (
uri VARCHAR2(30),
Texte VARCHAR2(100),
DH VARCHAR2(20),
metadonnee METADONNEE,
liens LIENS
)
NESTED TABLE liens STORE AS tliens;



--2
INSERT INTO RO VALUES ('ma-photo1', 'master blablabla', '12/05/09', 
METADONNEE('X. Tintin', GEO(43.8345267822, -0.232342), '03/04/08'), 
LIENS(
LIEN('Ma-photo2', 'Thème'), LIEN('Ma-photo12', 'reponse')));


--3


--4


--5


--6


--7

