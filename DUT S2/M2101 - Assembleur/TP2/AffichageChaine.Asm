.DATA
chaine DW "J'ai faim."

.CODE

LEA SP, STACK
	
	LD R0,0
	OUT R0,5 ;Pour effacer l'�cran
	LEA R0,chaine ;adresse de la chaine
	LD R1,100 ;coord x
	LD R2,100 ;coord y
	CALL affichageChaine
	HLT

affichageChaine:

	LD R3,'.'
	OUT R1,1 ;Coordon�e x de la chaine dans le port 1
	OUT R2,2 ;Coordon�e y de la chaine dans le port 2

	; Comme les coordon�es x et y sont automatiquement mises � jour on
	; ne les int�gre pas dans la boucle

	boucle:
	CMP R3, [R0] ;Si le caract�re point� par R0 est '.', on sort
	BEQ finAffichage
	OUT [R0],3 ;Caract�re de la chaine � afficher dans port 3
	LD R4, %11100111 ;Commande d'affichage (caract�re jaune)
	OUT R4,5 ; affichage du caract�re
	INC R0
	JMP boucle

	finAffichage:
	RET

.STACK 15