public class Velo extends SansMoteur {
    private int nb_vit;
    
    public Velo(String m, int vit){
        super(m);
        nb_vit=vit;
    }

    public String toString(){
        return "Velo " + super.toString() + ", " + nb_vit + " vitesses";
    }

    public void transporter(String depart, String arrivee){
        System.out.println("Le velo " + super.id + " se deplace de " + depart + " a " + arrivee );
    }

}
