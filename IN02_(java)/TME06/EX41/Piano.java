public class Piano extends Instrument{
    private int nb;

    public Piano(int touches , int po , int pr){
        super(po,pr);
        nb=touches;
    }

    public String toString(){
        return "Piano " + nb + " touches " + super.toString();
    }

    public void jouer(){
        System.out.println("Le Piano " + nb + " touches joue");
    }
}