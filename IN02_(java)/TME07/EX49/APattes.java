public abstract class APattes extends Animal {
    private int nbPattes;

    public APattes(String nom, int age, int nb){
        super(nom,age);
        this.nbPattes=nb;
    }

    public APattes(String nom, int nb){
        super(nom);
        this.nbPattes=nb;
    }

    public String toString(){
        return super.toString() + ", " + nbPattes + " pattes";
    }
}
