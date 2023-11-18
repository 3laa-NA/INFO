public abstract class Animal{
    protected String nom;
    private int age;

    public Animal(String nom,int age){
        this.nom=nom;
        this.age=age;
    }

    public Animal(String nom){
        this.nom=nom;
        this.age=1;
    }

    public String toString(){
        return "L'animal " + nom + " a " + age + " ans";
    }

    public void vieillir(){
        age++;
    }

    public abstract void crier();

}