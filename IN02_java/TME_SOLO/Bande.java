public class Bande {
    private  Monstre[] tab;
    private int max,cpt;

    public Bande(int max){
        tab = new Monstre[max];
        this.max=max;
    }

    public void ajouterMonstre(Monstre m){
        if(cpt<max){
            tab[cpt]=m;
            cpt++;
        }
    } 

    public int attaqueBande(){
        int degats=0;
        for(int i=0;i<cpt;i++){
            degats+=tab[i].attaque();
        }
        return degats;
    }

    public String toString() {
        String res = "La bande est composée de :\n";

        for(int i=0;i<cpt;i++){
            res+=tab[i].toString() + "\n";
        }

        return res;
    }
}
