public class Canard extends APattes {

    public Canard(String nom, int age){
        super(nom,age,2);
    }

    public Canard(String nom){
        super(nom,2);
    }

    public void crier(){
        System.out.println("Le canard " + this.nom + ": coin-coin ");
    }

    public String toString(){
        return super.toString() + " et est un canard";
    }
}
