
public class Tableau {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int tableau[] = {1,4,2,7,5,50,70,25,5,6};
		
		int traitementAUtiliser = 1;

		switch (traitementAUtiliser) {
		case 1 : afficher(tableau); break;
		case 2 : System.out.println(sommeTableau(tableau)); break;
		case 3 : trier(tableau, false); afficher(tableau); break;
		}

	}

	static void afficher (int [] tab)
	{
		for (int i = 0; i <= 9 ; i++) {
			System.out.println(tab[i]);
		}
	}
	
	static int sommeTableau (int [] tab)
	{
		int somme = 0;
		for (int i = 0; i <= 9 ; i++) {
			somme += tab[i];
		}
		
		return somme;
	}
	
	static void trier (int [] tab, boolean estCroissant)
	{
		int valeurCopie;
		
		if(estCroissant) {
			
			for (int i = 0; i <10 ; i++) {
				
				for (int j = 0; j <=8 ; j++) {
					
					if (tab[j] > tab[j+1]) {
						
						valeurCopie = tab[j];
						tab[j] = tab[j+1];
						tab[j+1] = valeurCopie;
					}
				}
			}
		}
		else {
			for (int i = 0; i <10 ; i++) {
				
				for (int j = 0; j <=8 ; j++) {
					
					if (tab[j] < tab[j+1]) {
						
						valeurCopie = tab[j];
						tab[j] = tab[j+1];
						tab[j+1] = valeurCopie;
					}
				}
			}
		}
		
	}
	
	static void TriFusion (int[] tabA, int[] tabB) {
		
		
		}
	}
