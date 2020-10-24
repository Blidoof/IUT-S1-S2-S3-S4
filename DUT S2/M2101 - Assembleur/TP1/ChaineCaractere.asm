.DATA

chaine DW "ddddzde"
       DW 0

maxi   DSW 1

.CODE

LEA SP, STACK

	LEA R2,chaine ; Adresse de la chaine dans R2
	LD R1,0
boucle: 
	LD R0,[R2]
	CMP R0,0
	BEQ egaux ; Si contenu de R0 = 0
	CALL max ;appel procédure max
	LD R1,R3
	ADD R2,1
	JMP boucle
egaux:  
	ST R3,maxi
	HLT

max:
	   CMP R0,R1
	   BGE plusgrand ; Si r0 supérieur ou égal à R1
	   LD R3,R1
	   JMP Finmax
plusgrand: LD R3,R0
Finmax:    RET

.STACK 10
