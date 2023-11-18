public class Saumon extends SansPattes{

    public Saumon(String nom, int age){
        super(nom,age);
    }

    public Saumon(String nom){
        super(nom);
    }

    public void crier(){
        System.out.println("...");
    }

    public String toString(){
        return super.toString() + " et est un saumon";
    }
}
