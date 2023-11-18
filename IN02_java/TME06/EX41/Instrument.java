public class Instrument{
    private int prix , poids ;

    public Instrument(int po , int pr){
        this.prix=pr;
        this.poids=po;
    }

    public String toString(){
        return "poids : " + poids + " kg, prix : " + prix + " euros.";
    }

    public void jouer(){
        System.out.println("L'instrument joue");
    }
}