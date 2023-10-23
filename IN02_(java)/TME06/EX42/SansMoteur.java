public class SansMoteur extends Vehicule {
    public SansMoteur(String m){
        super(m);
    }

    public String toString(){
        return super.toString() + " sans moteur";
    }
}
