
public class Charcuterie extends CharDAssaut {
	
	private final int ARME_DEFAUT_CHARCUTERIE = 50;
	private final int CARBU_DEFAUT_CHARCUTERIE = 1;
	
	public int getARME_DEFAUT_CHARCUTERIE() {
		return ARME_DEFAUT_CHARCUTERIE;
	}

	public int getCARBU_DEFAUT_CHARCUTERIE() {
		return CARBU_DEFAUT_CHARCUTERIE;
	}

	public Charcuterie(String nom) {
		super(nom);
		setDegats(ARME_DEFAUT_CHARCUTERIE);
		setVolumeCarburant(CARBU_DEFAUT_CHARCUTERIE);
	}
	

}
