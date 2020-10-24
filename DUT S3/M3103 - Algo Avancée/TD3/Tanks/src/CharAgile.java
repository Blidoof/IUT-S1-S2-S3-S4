import java.util.Random;

public class CharAgile extends CharDAssaut {
	
	 private final double PUISSANCE_CHAR_AGILE = getDegats()*0.8;
	 
	 public double getPUISSANCE_CHAR_AGILE() {
		return PUISSANCE_CHAR_AGILE;
	}

	public CharAgile(String nom) {
		 super(nom);
		 super.setDegats((int)PUISSANCE_CHAR_AGILE);
	 }
	 
	 public void recevoirDegats(CharDAssaut attaquant) {
		 Random rand = new Random();
		 int n = rand.nextInt(100);
		 
		 if (n <= 20 ) {
			 super.recevoirDegats(attaquant);
		 }
		 else {
			 System.out.println("Get Rekt ! "+ super.getNom() + " a évité " + attaquant.getDegats() + " dégats !");
		 }
	 }

}