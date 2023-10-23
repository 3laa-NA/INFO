public class Guitare extends Instrument{
    private String type;

    public Guitare(String type , int po , int pr){
        super(po,pr);
        this.type=type;
    }

    public String toString(){
        return "Guitare " + type + " " + super.toString();
    }

    public void jouer(){
        System.out.println("La guitare " + type + " joue");
    }
}
