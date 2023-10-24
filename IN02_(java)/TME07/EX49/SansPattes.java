public abstract class SansPattes extends Animal {
    
    public SansPattes(String nom, int age){
        super(nom,age);
    }

    public SansPattes(String nom){
        super(nom);
    }

    public String toString(){
        return super.toString() + ", sans pattes";
    }
}
