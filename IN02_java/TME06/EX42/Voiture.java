public class Voiture extends AMoteur {
    private int nb_plc;

    public Voiture(String m, double cap, int nb){
        super(m,cap);
        nb_plc=nb;
    }

    public String toString(){
        return "Voiture " + super.toString() + ", " + nb_plc + " places";
    }

    public void transporter(int nbPers, int km){
        if(super.enPanne()){
            System.out.println("La voiture " + super.id + " n'a plus d'essence !");
        }

        else{
            if(nbPers>nb_plc){
            System.out.println("La voiture " + super.id + " n'est pas assez grande !");
            }

            else{
            super.dis+=km;
            System.out.println("La voiture " + super.id + " transporte " + nbPers + " personnes sur " + km + " km");
            }
        }
    }
}
