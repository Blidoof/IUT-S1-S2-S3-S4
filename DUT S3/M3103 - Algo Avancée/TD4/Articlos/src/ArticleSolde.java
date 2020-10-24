
public class ArticleSolde extends Article {
	private int remiseSolde;
	
	public ArticleSolde (String code, double prix, int remise) {
		super (code, prix);
		this.remiseSolde = remise;
	}
	
	public double getPrix() {
		return (super.getPrix()*(1-(remiseSolde*0.01)));
	}

}
