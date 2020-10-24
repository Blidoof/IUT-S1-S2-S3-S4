--1
CREATE TYPE B_point AS OBJECT (
x NUMBER(3),
y NUMBER(3) );

--2
CREATE TYPE Ligne AS OBJECT (
origine B_point,
arrivee B_point );

--3
CREATE TYPE Polygone AS TABLE OF B_point;

--4CREATE TABLE Region (
nom VARCHAR2(50) PRIMARY KEY,
surface Polygone)
NESTED TABLE surface STORE AS tabPoly;

--5
INSERT INTO Region VALUES ('Aquitaine', POLYGONE(B_POINT(4,7), B_POINT(1,2)));

--6
CREATE TYPE Rect AS OBJECT (
origine B_point,
arrivee B_point);

--7
CREATE TABLE Ville (
nom VARCHAR2(30),
Surface Rect);

--8
INSERT INTO Ville VALUES ('Anglet', RECT(B_POINT(895, 918), B_POINT(484, 505)));
INSERT INTO Ville VALUES ('Paris', RECT(B_POINT(631,656), B_POINT(294,311)));

--9
SELECT nom, ABS(((surface).arrivee.x - (surface).origine.x)*((surface).arrivee.y - (surface).origine.y)) FROM ville;

--10
SELECT nom
FROM ville 
WHERE ABS((surface).arrivee.x - (surface).origine.x) > 10
OR ABS((surface).arrivee.y - (surface).origine.y) > 10

