/*
 Alaa ALABOUD
 Ichraq MOHAMMAD
*/

public class Gardien extends Contenu{
    private int hp;
    private static int cpt=0;
    private final int id;

    public Gardien(){
        super("Gardien",1);
        hp=(int)(Math.random()*201);
        cpt++;
        id=cpt;
    }
    public int getHp(){return hp;}

    //simulation d'une frappe par l'agent
    public void hit(int f){
        hp-=f;
    }

}