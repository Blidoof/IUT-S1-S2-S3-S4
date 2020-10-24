.DATA

la DW 40 ; largeur ellipse loutre
ha DW 20 ; hauteur ellipse loutre
germe DW 12345678
m DW 2147483647
a DW 16807
score DW 0 ;Score joueur
	  DW 0
	  DW 0
	  DW 0
	  DW 0
	  DW 0
	  DW 0
	  DW 0
	  DW 0
	  DW 0
pointeur DSW 1 ;pointeur sur score
chaine DSW 20 ; chaine a afficher


chaineNiveau1 DW "Niveau : 1."
chaineNiveau2 DW "Niveau : 2."
chaineNiveau3 DW "Niveau : 3."
chaineNiveau4 DW "Niveau : 4."

couleur DSW 1
xChaine DSW 1
yChaine DSW 1
xCarre DSW 1
yCarre DSW 1

.CODE
LEA SP, STACK
	
	;On efface l'écran
	LD R0,0
	OUT R0,5
	
	;On prepare les paramètres pour la procédure d'affichage du niveau 1
	LEA R0,chaineNiveau1
	LD R1,95
	LD R2,50
	CALL affichageChaine
	LD R0,%1111
	PUSH R0
	LD R0,90
	PUSH R0
	LD R0,38
	PUSH R0
	
	IN R0,1
	ADD R0,10
	PUSH R0
	LD R0,17
	PUSH R0
	CALL rectangle
	HLT
	
	

affichageChaine:

	LD R3,'.'
	OUT R1,1 ;Coordonée x de la chaine dans le port 1
	OUT R2,2 ;Coordonée y de la chaine dans le port 2

	; Comme les coordonées x et y sont automatiquement mises à jour on
	; ne les intègre pas dans la boucle

	boucle:
	CMP R3, [R0] ;Si le caractère pointé par R0 est '.', on sort
	BEQ finAffichage
	OUT [R0],3 ;Caractère de la chaine à afficher dans port 3
	LD R4, %11110111 ;Commande d'affichage (caractère blanc)
	OUT R4,5 ; affichage du caractère
	INC R0
	JMP boucle

	finAffichage:
	RET
	
rectangle:
	PUSH R0
	LD R0, [SP+2] ;hauteur dans port 4
	OUT R0,4
	LD R0, [SP+3];largeur dans port 3
	OUT R0,3
	LD R0, [SP+4];coordY dans port 2
	OUT R0,2
	LD R0, [SP+5];coordX dans port 1
	OUT R0,1
	LD R0, 3 ;On ajoute la commande graphique a effectuer (rectangle) dans R0
	SHL [SP+6] ;Décalage de 4 bits à gauche de codeCoul pour pouvoir l'ajouter a la commande graphique dans R0
	SHL [SP+6]
	SHL [SP+6]
	SHL [SP+6]
	ADD R0, [SP+6] ;On concatenne codeCoul a la commande graphique
	OUT R0, 5 ;Dessin du rectangle de couleur codeCoul, de hauteur hauteur, de largeur largeur, 
			  ;et dont le coin supérieur gauche a pour coordonées coordX,coordY
	PULL R0
	RET 5
	

.STACK 15