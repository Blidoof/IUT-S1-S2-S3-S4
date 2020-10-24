.DATA
chaine DW "J'ai faim."

.CODE

LEA SP, STACK
	
	LD R0,0
	OUT R0,5 ;Pour effacer l'écran
	LEA R0,chaine ;adresse de la chaine
	LD R1,100 ;coord x
	LD R2,100 ;coord y
	CALL affichageChaine
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
	LD R4, %11100111 ;Commande d'affichage (caractère jaune)
	OUT R4,5 ; affichage du caractère
	INC R0
	JMP boucle

	finAffichage:
	RET

.STACK 15