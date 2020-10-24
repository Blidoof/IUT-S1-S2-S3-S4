.DATA
coordX DW 78
coordY DW 78
largeur DW 100
hauteur DW 100

.CODE
LEA SP, STACK
	
	;on efface l'écran au début
	LD R0,0 
	OUT R0,5
	
	;Dessin du carré initial au centre de l'écran
	PUSH coordX
	PUSH coordY
	PUSH largeur
	PUSH hauteur
	CALL carre100 ;appel procédure dessin
	
	

boucle:
 
	;Attente de clic sur les boutons
	IN R1,0 ;Recuperation de valeur du port 0 pour connaitre état clavier
	CMP R1,%11000101 ;Si on appuie sur A
	BEQ Aappuye
	CMP R1,%10000101 ;Si on relache A
	BEQ Alache
	CMP R1,%11000110 ;Si on appuie sur B
	BEQ Bappuye
	JMP boucle ; Si pas d'action, on teste a nouveau
	
Aappuye:

	;Si on appuie sur A, on réduit la largeur et la hauteur de 50, et
	;on décale le coin supérieur gauche de +25 sur x et y pour le placer au centre
	LD R2,largeur 
	SUB R2,50	  
	ST R2,largeur
	LD R2,hauteur
	SUB R2,50
	ST R2,hauteur
	LD R2, coordX
	ADD r2,25
	ST R2,coordX
	LD R2, coordY
	ADD r2,25
	ST R2,coordY
	PUSH coordX ;On met a nouveau les paramètres dans la pile pour pouvoir dessiner
	PUSH coordY
	PUSH largeur
	PUSH hauteur
	CALL carre50 ;appel procédure dessin (carre50 efface le dessin precedent, pas carre100)
	JMP boucle ;On revient a l'attente d'action

Alache:

	;Meme technique que quand on appuie sur A, si on relache on agrandit
	; a nouveau le carre de +50, et on le décale de -25 sur x et y
	; pour le placer au centre
	LD R2,largeur
	ADD R2,50	  
	ST R2,largeur
	LD R2,hauteur
	ADD R2,50
	ST R2,hauteur
	LD R2, coordX
	SUB r2,25
	ST R2,coordX
	LD R2, coordY
	SUB r2,25
	ST R2,coordY
	PUSH coordX
	PUSH coordY
	PUSH largeur
	PUSH hauteur
	CALL carre100 ;appel procédure dessin
	JMP boucle ;On revient a l'attente d'action
	
Bappuye: 

	;Si B est appuyé, on arrête le programme
	JMP fin
	
fin:
	HLT
	
	
carre100:
	;Pas d'effacement necessaire au début car le plus grand carre recouvre le plus petit
	PUSH R0
	LD R0, [SP+2] ;hauteur dans port 4
	OUT R0,4
	LD R0, [SP+3];largeur dans port 3
	OUT R0,3
	LD R0, [SP+4];coordY dans port 2
	OUT R0,2
	LD R0, [SP+5];coordX dans port 1
	OUT R0,1
	LD R0, %01110101 ;On ajoute la commande graphique a effectuer (rectangle plein vert) dans R0
	OUT R0, 5 ;On dessine
	PULL R0
	RET 5
	
carre50:

	;on efface l'écran
	LD R0,0 
	OUT R0,5
	
	PUSH R0
	LD R0, [SP+2] ;hauteur dans port 4
	OUT R0,4
	LD R0, [SP+3];largeur dans port 3
	OUT R0,3
	LD R0, [SP+4];coordY dans port 2
	OUT R0,2
	LD R0, [SP+5];coordX dans port 1
	OUT R0,1
	LD R0, %01110101 ;On ajoute la commande graphique a effectuer (rectangle plein vert) dans R0
	OUT R0, 5 ;On dessine
	PULL R0
	RET 5
	
	
	
.STACK 15