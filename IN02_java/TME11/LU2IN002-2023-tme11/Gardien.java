/*
 Alaa ALABOUD
 Ichraq MOHAMMAD
*/

public class Gardien extends Contenu {
    private int hp;
    private static int cpt=1;
    private final int id;

    public Gardien(){
        super("Gardien",cpt);
        hp=(int)(Math.random()*201);
        id=cpt;
        cpt++;
    }
    public int getHp(){return hp;}

    public void hit(int f){
        hp-=f;
    }
}


