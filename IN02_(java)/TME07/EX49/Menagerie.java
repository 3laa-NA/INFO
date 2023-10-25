public class Menagerie {
    private int max;
    private Animal[] l;
    private int nb_animal=0;

    public Menagerie(int m){
        max=m;
        this.l = new Animal[m];
    }

    public void ajouter(Animal x){
        if (nb_animal<max){
            l[nb_animal] = x ;
            nb_animal ++;
        }
        else{System.out.println("pas de place dans la menagerie");}
    }

    public String toString(){
        String res="";
        for(int i=0 ; i<nb_animal ; i++){
            res+=l[i].toString() + "\n";
        }
        return res;
    }

    public void midi(){
        for(int i=0 ; i<nb_animal ; i++){
            l[i].crier();
        }
    }

    public void vieillirTous(){
        for(int i=0 ; i<nb_animal ; i++){
            l[i].vieillir();
        }
    }

    public static void main(String[] args) {
        Vache v1 = new Vache("V1");
        Boa b1 = new Boa("B1");
        Canard c1 = new Canard("C1");
        Saumon s1 = new Saumon("S1");
        MillePattes m1 = new MillePattes("M1");

        System.out.println(v1.toString());
        System.out.println(b1.toString());
        System.out.println(c1.toString());
        System.out.println(s1.toString());
        System.out.println(m1.toString());

        Menagerie mena1 = new Menagerie(10);

        mena1.ajouter(v1);
        mena1.ajouter(b1);
        mena1.ajouter(c1);
        mena1.ajouter(s1);
        mena1.ajouter(m1);

        System.out.println(mena1.toString());

        mena1.midi();

        mena1.vieillirTous();
        
        System.out.println(mena1.toString());
    }
}
