#include "libTPIUT.h"
#include "robot.h"
#define PORT_BP1 PortB
#define PORT_BP2 PortC
#define PORT_DELD PortB
#define PORT_DELC PortA
#define PORT_DELG PortC
#define LIGNE_DELD 27
#define LIGNE_DELC 21
#define LIGNE_DELG 30
#define LIGNE_BP1 25
#define LIGNE_BP2 26
#define RESET 6

void init();
void changerDiode(int moteur);
void allumerDiodes(int gauche, int milieu, int droite);

int main (void)
{
	initCarte();
	initRobot();
	configureConsole();
	init();
	int cycle = 0;
	int moteur = 0;
	float tabPosition[4] = {0,10,0,-10};
	int moteurs[6] = {BASE, EPAULE, COUDE, POIGNET, PINCE, RESET};
	while(true) {
		if (lireLigne(PORT_BP1, LIGNE_BP1) == 1) {
			if (moteurs[moteur] == RESET){
				initRobot();
			}
			else {			
				positionnerMoteur(moteurs[moteur], tabPosition[cycle]);
				cycle =(cycle+1)%4;
			}
			while(lireLigne(PORT_BP1, LIGNE_BP1) == 1);

		}
		
		if (lireLigne(PORT_BP2,LIGNE_BP2) == 1)
		{
			moteur = (moteur+1)%6;
			changerDiode(moteur);	
			while(lireLigne(PORT_BP2,LIGNE_BP2) == 1) {}
		}
	}
}



void changerDiode(int moteur) {
	switch(moteur) {
		case 0: 
			allumerDiodes(1,1,1); //Droite allumée quand coude
			break;
		case 1: 
			allumerDiodes(1,0,0); //milieu allumée quand coude
			break;
		case 2: 
			allumerDiodes(1,0,1); //Droite et milieu allumée quand coude
			break;
		case 3: 
			allumerDiodes(0,1,0); //gauche allumée quand coude
			break;
		case 4: 
			allumerDiodes(0,1,1); //gauche allumée quand coude
			break;
		case 5 :
			allumerDiodes(0,0,1); //Toutes allumées
			break;
	}
}

void allumerDiodes(int gauche, int milieu, int droite) {
	ecrireLigne(PORT_DELG, LIGNE_DELG, gauche);
	ecrireLigne(PORT_DELC, LIGNE_DELC, milieu);
	ecrireLigne(PORT_DELD, LIGNE_DELD, droite);
}

void init() {
	allumerPeriph(PORT_BP1);
	allumerPeriph(PORT_BP2);
	allumerPeriph(PORT_DELC);
	programmerLigne(PORT_BP1, LIGNE_BP1, ENTREE);
	programmerLigne(PORT_BP2, LIGNE_BP2, ENTREE);
	programmerLigne(PORT_DELC, LIGNE_DELC, SORTIE1 );
	programmerLigne(PORT_DELD, LIGNE_DELD, SORTIE1);
	programmerLigne(PORT_DELG, LIGNE_DELG, SORTIE1);
	activerFiltrageLigne(PORT_BP1, LIGNE_BP1, 20);
	activerFiltrageLigne(PORT_BP2, LIGNE_BP2, 20);
}