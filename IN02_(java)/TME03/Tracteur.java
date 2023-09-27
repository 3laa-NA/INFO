public class Tracteur {
    private Roue r1, r2, r3, r4;
    private Cabine c1;

    public Tracteur(Roue r1,Roue r2,Roue r3,Roue r4, Cabine c1){
        this.r1 = r1;
        this.r2 = r2;
        this.r3 = r3;
        this.r4 = r4;
        this.c1 = c1;
        
    }
    public Tracteur(){
        this.r1 = new Roue();
        this.r2 = new Roue();
        this.r3 = new Roue();
        this.r4 = new Roue();
        this.c1 = new Cabine(3,"bleu");
        
    }
    public String toString(){
        return "r1 : " + r1 + ", r2 : " +  r2  + ", r3 : " + r3 +  ", r4 : " + r4 + ", c1 : " + c1;
    }

    public void peindre(String couleur){
        this.c1.setCouleur(couleur);
    }

    public Tracteur (Tracteur t1){
        this.r1 = new Roue (t1.r1);
        this.r2 = new Roue (t1.r2);
        this.r3 = new Roue (t1.r3);
        this.r4 = new Roue (t1.r4);
        this.c1 = new Cabine (t1.c1);

    }

}
