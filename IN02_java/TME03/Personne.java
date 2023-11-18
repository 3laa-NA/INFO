public class Personne {
    private String nom;
    private Personne conjoint;

    public Personne(String nom){
        this.nom = nom;
        this.conjoint = null;
    }

    public Personne(){
        this.nom = "pers" + (char)('A' + Math.random() * 26);
        this.conjoint = null;
    }

    public String toString(){
        return this.nom + ", " + (this.conjoint == null ? "célibataire" : "marié(e)");
    }
    
    public void epouser(Personne p){
        if(p == null || this.nom.equals(p.nom)){
            System.out.println("Le mariage est impossible");
        }


        else if(this.conjoint != null || p.conjoint != null){
            System.out.println("Le mariage de " + this.toString() + " avec " + p.toString() + " est impossible");
        }

        else {
            System.out.println(this.toString() + " se marie avec " + p.toString());
            this.conjoint = p;
            p.conjoint = this;
        }
    }

    public void divorcer(){
            
        if(this.conjoint == null){
            System.out.println("Le divorce est impossible");
        }

        else {
            System.out.println(this.toString() + " divorce de " + this.conjoint.toString());
            this.conjoint.conjoint = null;
            this.conjoint = null;
        }
        
    }

    public static void main(String[] args) {
        Personne p1 = new Personne();
        Personne p2 = new Personne();
        Personne p3 = new Personne();

        System.out.println("p1 : " + p1.toString());
        System.out.println("p2 : " + p2.toString());
        System.out.println("p3 : " + p3.toString());

        p1.epouser(p2);
        p1.epouser(p3);
        p3.epouser(p1);
        p3.epouser(p3);

        System.out.println("p1 : " + p1.toString());
        System.out.println("p2 : " + p2.toString());
        System.out.println("p3 : " + p3.toString());

        p1.divorcer();
        p3.divorcer();
        
        System.out.println("p1 : " + p1.toString());
        System.out.println("p2 : " + p2.toString());
        System.out.println("p3 : " + p3.toString());
    

    }
}

