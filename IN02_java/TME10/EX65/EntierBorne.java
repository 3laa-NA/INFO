public class EntierBorne {
    private int valeur;
    private final int MAX=100;
    private final int MIN=-100;

    public EntierBorne(int i) throws HorsBornesException{
        if(i>MAX){
            throw new HorsBornesException("Entier trop grand : " + i);
        }

        if(i<MIN){
            throw new HorsBornesException("Entier trop petit : " + i);
        }

        valeur=i;
    }

    public EntierBorne somme(EntierBorne eb) throws HorsBornesException{
        return new EntierBorne(this.valeur+eb.valeur);
    }

    public EntierBorne divPar(EntierBorne eb) throws DivisionParZeroException ,HorsBornesException{
        if(eb.valeur==0){
            throw new DivisionParZeroException();
        }
        return new EntierBorne(this.valeur/eb.valeur);
    }

}
