
public class CharDAssaut {
	private String nom;
	private int degats;
	private int volumeCarburant;
	private final int CARBURANT_CHAR_BASIQUE = 100;
	private final int PUISSANCE_BASIQUE = 10;
	
	public int getCARBURANT_CHAR_BASIQUE() {
		return CARBURANT_CHAR_BASIQUE;
	}

	public int getPUISSANCE_BASIQUE() {
		return PUISSANCE_BASIQUE;
	}

	public CharDAssaut (String nom) {
		this.nom = nom;
		volumeCarburant = CARBURANT_CHAR_BASIQUE;
		degats = PUISSANCE_BASIQUE;
		
	}
	
	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public int getDegats() {
		return degats;
	}

	public void setDegats(int degats) {
		this.degats = degats;
	}

	public int getVolumeCarburant() {
		return volumeCarburant;
	}

	public void setVolumeCarburant(int volumeCarburant) {
		this.volumeCarburant = volumeCarburant;
	}

	public void tirer (CharDAssaut cible) {
		cible.recevoirDegats(this);
		System.out.println("Pan ! " + nom + " a infligé " + this.getDegats() + " dégats à " + cible.getNom() );
		
	}

	public void recevoirDegats (CharDAssaut attaquant) {
		volumeCarburant -= attaquant.getDegats();
		System.out.println("Ouch ! " + nom + " a recu " + attaquant.getDegats() + " dégats !");
	}
}
