public class MillePattes extends SansPattes {

    public MillePattes(String nom, int age){
        super(nom,age);
    }

    public MillePattes(String nom){
        super(nom);
    }

    public void crier(){
        System.out.println("...");
    }

    public String toString(){
        return super.toString() + " et est un mille-pattes";
    }
}

