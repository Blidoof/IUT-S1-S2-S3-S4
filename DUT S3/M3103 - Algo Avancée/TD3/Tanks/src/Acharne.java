
public class Acharne extends CharBouclier {
	
	public Acharne (String nom) {
		super(nom);
	}
	
	public void recevoirDegats (CharDAssaut attaquant) {
		if (super.getBouclier() == 0) {
			super.recevoirDegats(attaquant);
			
		}
		else {
			super.setBouclier(super.getBouclier()-1);
			setDegats(getDegats()+10);
			System.out.println("Get Rekt ! " + super.getNom() + " a résisté à " + attaquant.getDegats() + " dégats et est devenu plus puissant ! ");
		}
	}
	

}
