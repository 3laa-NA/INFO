import java.util.ArrayList;
import java.text.DecimalFormat;

public class Panier extends ArrayList<Ramassable> {
    private double poidsMax;

    public Panier(double pMax){
        poidsMax=pMax;
    }

    public double getPoids() {
        double res = 0.;
        for(int i=0 ; i < this.size();i++){
            res+=(this.get(i)).getPoids();
        }
        return res;
    }

    @Override
    public boolean add(Ramassable e) {
        double tmp = this.getPoids();
        if(tmp+(e.getPoids())<=poidsMax){
            super.add(e);
            System.out.println(e.toString() +" est ajouté au panier");
            return true;
        }
        else{
            System.out.println(e.toString() +" n'est pas ajouté au panier");
            return false;
        }
    }

    public int compterToxiques(){
        int res = 0;
        for(int i=0 ; i < this.size();i++){
            if(this.get(i) instanceof Toxique){
                res++;
            }
        }
        return res;
    }

    public String toString() {
        DecimalFormat df = new DecimalFormat("#.##");
        return "Panier contenant " + this.size() + " objets, dont " + this.compterToxiques() + " toxiques (" + Double.parseDouble(df.format(this.getPoids())) + "kg sur " + poidsMax + "kg)" ;
    }

}
