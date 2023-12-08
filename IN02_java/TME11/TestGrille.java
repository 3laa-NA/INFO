/**
 * @author Christophe Marsala (LU2IN002 2023oct)
 * 
 * Gestion d'une Grille
 *
 */

import java.util.ArrayList;

public class TestGrille {

	/**
	 * @param args
	 */ 
	public static void main(String[] args) {
		// Exemple de création de Grille
		Grille t = new Grille(4,5);
		
		// Grille initiale : elle est vide
		t.affiche(2);
		
		// Informations sur la Grille
		System.out.println("Informations sur la grille:\n"+t);		
		
		// On créé un Contenu en donnant son nom et sa quantité
		Contenu e1 = new Contenu("Cepe",5);
		
		// tentative de mauvais placement:
		try {
			t.setCase(7,41,e1);
			System.out.println("Ajout de " +e1+" valide !");
		}
		catch (CoordonneesIncorrectesException e) {
			System.out.println("Erreur: "+e.getMessage());
		}
	
		// placement correct sur la Grille
		try {
			t.setCase(2,3,e1);
			System.out.println("Ajout de " +e1+" valide !");
		}
		catch (CoordonneesIncorrectesException e) {
			System.out.println("Erreur: "+e.getMessage());
		}
		
		// Affichage de la Grille avec les Contenus ajoutés
		t.affiche(6);
		// Informations sur la Grille
		System.out.println("Informations sur la grille:\n"+t);
		
		// Contenu d'une case:
		try {
			System.out.println("Dans la case (1,4): "+t.getCase(1,4));
			System.out.println("Liste de tous les Contenus présents actuellement:");
		}
		catch (CoordonneesIncorrectesException e) {
			System.out.println("Erreur: "+e.getMessage());
		}
				
		ArrayList<Contenu> liste = t.lesContenus();
		for (Contenu r : liste) {
			System.out.println(r);
		}
		
	}

}
