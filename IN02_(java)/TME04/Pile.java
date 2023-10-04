public class Pile{
    private Assiette [] tab;
    private int nbA;

    public Pile(int n){
        this.tab = new Assiette [n];
    }

    public boolean estVide(){
        if(nbA == 0){
            return true;
        }
        return false;
    }

    public boolean estPleine(){
        if (tab.length==nbA){
            return true;
        }
        return false;
    }

    public void empiler(Assiette a){
        if (!(this.estPleine())){
            tab[nbA] = a;
            nbA++; 
        }   
    }

    public Assiette depiler(){
        if(!(this.estVide())){
            nbA --;
            return tab[nbA];
        }
        return null;
    }

    public String toString(){
        String res ="";
        for(int i=nbA ; i>0 ; i--){
            res +="\\_____/ \n";
        }
        return res;
    }

}