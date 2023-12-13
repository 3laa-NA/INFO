/*
 Alaa ALABOUD
 Ichraq MOHAMMAD
*/

public class Joyau extends Contenu {

    private int prix; //en pièces d'or
    private static int cpt=0;
    private final int id;
    private String type;

    public Joyau(String type){
        super(type,1);
        this.type = type;
        prix=(int)(Math.random()*4000)+1;
        cpt++;
        id=cpt;
    }

    public int getPrix(){return prix;}

    public String getType(){return type;}

}