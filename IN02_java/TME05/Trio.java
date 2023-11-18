public class Trio {
    public Personne[] tab ;
    private static int compteur= 0;

    public Trio(){
        compteur++;

        tab = new Personne[3];
        for (int i = 0; i < 3; i++) {
            tab[i] = new Personne();
        }
    }

    public static int getNbTrios(){ return compteur; }

    public String toString(){
        return "Trio " + compteur + " : " + tab[0].toString() + " " + tab[1].toString() + " " + tab[2].toString();
    }
}
