public class Vache extends APattes {
    public double lait;

    public Vache(String nom, int age){
        super(nom,age,4);
        this.lait= Math.random()*25 +5;
    }

    public Vache(String nom){
        super(nom,4);
        this.lait= Math.random()*25 +5;
    }

    public void crier(){
        System.out.println("La vache " + this.nom + " meugle");
    }

    public String toString(){
        return super.toString() + " et est une vache qui produit " + lait + " litres de lait";
    }
}
