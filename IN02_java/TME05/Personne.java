public class Personne {
    private String nom;
    private static int nbPersonnes = 0;
    private char lettre = 'A' ;
    
    public Personne(){
        //nbPersonnes++; # pour Individu1 , ..2 , ..3 etc...
        this.nom = "Individu" + (char)(lettre + nbPersonnes) ;
        nbPersonnes++;
    }

    public static int getNbPersonnes(){ return nbPersonnes; }

    public String toString(){ return nom; }
}
