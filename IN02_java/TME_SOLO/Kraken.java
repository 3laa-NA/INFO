public class Kraken extends MonstreMarin{
    private int nbTentacules ;

    public Kraken(int force,int nbTentacules,String grandeur){
        super(force, grandeur);
        this.nbTentacules = nbTentacules;
    }

    public int attaque(){
        if(super.grandeur=="geant"){
            return super.force * nbTentacules;
        }else{
            return (super.force>this.nbTentacules) ? super.force : this.nbTentacules;
        }
        
    }

    public String toString() {
        return "Kraken a " + nbTentacules + " tentacules " + super.toString();
    }
}
