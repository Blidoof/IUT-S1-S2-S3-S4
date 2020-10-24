import java.util.Random;

public class MatuidiCharo extends CharDAssaut {
	
	public MatuidiCharo(String nom) {
		super(nom);
	}
	
	public void tirer(CharDAssaut cible) {
		
		 Random rand = new Random();
		 int n = rand.nextInt(100);
		 
		 if (n >= 35) {
			 setDegats(getDegats()+5);
			 super.tirer(cible);
			 System.out.println("Coup critique !" );
			 setDegats(getDegats()-5);
		 }
		 else {
			 super.tirer(cible);
		 }
		
	}

}
