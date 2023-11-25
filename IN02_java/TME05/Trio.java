public class Trio {
    private Personne[] tab ;
    private int numeroTrio; 
    private static int compteur= 0;

    public Trio(){
        compteur++;
        numeroTrio = compteur; 
        tab = new Personne[3];
        for (int i = 0; i < 3; i++) {
            tab[i] = new Personne();
        }
    }

    public static int getNbTrios(){ return compteur; }

    public String toString(){
        return "Trio " + compteur + " : " + tab[0] + " " + tab[1] + " " + tab[2];
    }
}
