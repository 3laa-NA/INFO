public abstract class Monstre {
    protected int force;
    private static int cpt=0;
    private final int id;
    private String habitat;

    public Monstre(int force, String habitat){
        cpt++;
        id=cpt;
        this.habitat=habitat;
        this.force=force;
    }

    public abstract int attaque();

    public int getForce(){return force;}

    public String toString() {
        return "force " + force + " - habitat : " + habitat + ", id : " + id;
    }
}
