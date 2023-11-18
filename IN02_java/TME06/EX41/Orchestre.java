public class Orchestre {
    private int max;
    private Instrument[] l;
    private int nb_inst=0;

    public Orchestre(int m){
        max=m;
        this.l = new Instrument[m];
    }

    public void ajouterInstrument(Instrument x){
        if (nb_inst<max){
            l[nb_inst] = x ;
            nb_inst ++;
        }
        else{System.out.println("pas de place dans l'orchestre");}
    }

    public void jouer(){
        for(int i=0 ; i<nb_inst ; i++){
            l[i].jouer();
        }
    }
}

