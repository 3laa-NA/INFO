public class Loup extends MonstreTerrestre {

    public Loup(int force,String habitat,String couleur){
        super(force,habitat,couleur);
    }
    
    public int attaque(){
        return super.force + (int)(Math.random()*5 + 1);
    }

    public String toString() {
        return "Loup " + super.toString();
    }
}
