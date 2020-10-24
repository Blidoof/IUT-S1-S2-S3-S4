import java.util.HashMap;
import java.util.Map;

public class GestionArticles {
	
	private Map <String, Article> Articles;
	
	public GestionArticles () {
		Articles = new HashMap<String, Article>();
	}
	
	public void ajouterArticle(Article objet) {
		Articles.put(objet.getCodeBarres(), objet);
		System.out.println("L'article de prix " + objet.getPrix() + " et de code " + objet.getCodeBarres() + " a été ajouté !");
	}
	
	public double getPrixArticle (String code) {
		
		if (Articles.get(code) != null) {
			System.out.println("L'article de code " + code + " est à : " + Articles.get(code).getPrix() + "€");
			return Articles.get(code).getPrix();
		}
		else {
			System.out.println("Dude, it doesn't even exist !");
			return -1.0;
		}
	}
	
	public void setPrixArticle (String code, int prix) {
		System.out.println("Ancien prix : " + Articles.get(code).getPrix());
		Articles.get(code).setPrix(prix);
		System.out.println("Nouveau prix : " + Articles.get(code).getPrix());
		
	}
	
	public void enleverArticle(String code) {
		Articles.remove(code);
		System.out.println("L'article de code " + code + " a été retiré !");
	}

}
