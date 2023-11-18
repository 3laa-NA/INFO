public class Vehicule {
    public static int cpt=0;
    protected int id;
    private String marque;
    protected double dis=0;

    public Vehicule(String m){
        marque = m;
        cpt++;
        id = cpt;
    }
    public String toString(){
        return id + " de marque " + marque;
    }

    public void rouler(double distance){
        dis+=distance;
        System.out.println( this.toString() + " a roule " + distance + " km" );
    }
}
