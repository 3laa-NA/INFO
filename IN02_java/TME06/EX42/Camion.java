public class Camion extends AMoteur {
    private double v;

    public Camion(String m, double cap, int vol){
        super(m,cap);
        v=vol;
    }

    public String toString(){
        return "Camion " + super.toString() + ", volume : " + v;
    }

    public void transporter(String materiau, int km){
        if(super.enPanne()){
            System.out.println("Le camion " + super.id + " n'a plus d'essence !");
        }

        else{
            super.dis+=km;
            System.out.println("Le camion " + super.id + " a transporte des " + materiau + " sur " + km + " km");
        }
    }
}
