
public class Article {
	private String codeBarres;
	private double prix;
	
	public Article (String code, double prix) {
		codeBarres = code;
		this.prix = prix;
	}
	
	public String getCodeBarres() {
		return codeBarres;
	}
	public void setCodeBarres(String codeBarres) {
		this.codeBarres = codeBarres;
	}
	public double getPrix() {
		return prix;
	}
	public void setPrix(double prix) {
		this.prix = prix;
	}
	
	
}
