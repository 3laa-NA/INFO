public class Boa extends SansPattes {

    public Boa(String nom, int age){
        super(nom,age);
    }

    public Boa(String nom){
        super(nom);
    }
    
    public void crier(){
        System.out.println("...");
    }

    public String toString(){
        return super.toString() + " et est une boa";
    }
}
