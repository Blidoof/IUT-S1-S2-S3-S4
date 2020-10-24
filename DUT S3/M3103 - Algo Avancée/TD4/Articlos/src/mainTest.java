
public class mainTest {

	public static void main(String[] args) {
	Article boiteAMeuh = new Article ("17AAA6", 3);
	ArticleSolde gode = new ArticleSolde ("663JN2", 56, 10);
	GestionArticles gestionnaire = new GestionArticles();
	
	gestionnaire.ajouterArticle(boiteAMeuh);
	gestionnaire.ajouterArticle(gode);
	
	gestionnaire.getPrixArticle("17AB47");
	
	gestionnaire.enleverArticle("663JN2");
	}

}
