
public class CharBouclier extends CharDAssaut {
	
	private final int BOUCLIER_CHAR_DEFAUT = 3;
	
	public int getBOUCLIER_CHAR_DEFAUT() {
		return BOUCLIER_CHAR_DEFAUT;
	}

	private int bouclier;
	
	public int getBouclier() {
		return bouclier;
	}

	public void setBouclier(int bouclier) {
		this.bouclier = bouclier;
	}

	public CharBouclier (String nom) {
		super(nom);
		bouclier = BOUCLIER_CHAR_DEFAUT;
		
	}
	
	public void recevoirDegats (CharDAssaut attaquant) {
		if (bouclier == 0) {
			super.recevoirDegats(attaquant);
		}
		else {
			bouclier --;
			System.out.println("Get Rekt ! " + super.getNom() + " a résisté à " + attaquant.getDegats() + " dégats !");
		}
	}
	

}
