/*
 Alaa ALABOUD
 Ichraq MOHAMMAD
*/

public class Joyau extends Contenu {
    private int prix;
    private static int cpt=1;
    private final int id;

    public Joyau(String type){
        super(type,cpt);
        prix=(int)(Math.random()*4000)+1;
        id=cpt;
        cpt++;
    }
    public int getPrix(){return prix;}
}
