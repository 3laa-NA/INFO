public class Complexe{
    private double reelle, imag;

    public Complexe(double reelle, double imag){
        this.reelle = reelle;
        this.imag = imag;
    }

    public Complexe(){
        this(-2 + Math.random() * 4, -2 + Math.random() * 4);
    }

    public String toString() {
        return String.format("%.2f", this.reelle) + " + " + String.format("%.2f", this.imag) + "i";
    }    

    public String estReel() {
        return (this.imag == 0) ? "oui" : "non" ;
    }

    public String addition(Complexe z) {
        //return (this.reelle + z.reelle)+ " + " + (this.imag + z.imag) + " i" ;
        return String.format("%.2f", (this.reelle + z.reelle)) + " + " + String.format("%.2f", (this.imag + z.imag)) + "i";
    }

    public String multiplication(Complexe z) {
        double a1 = this.reelle;
        double b1 = this.imag;
        double a2 = z.reelle;
        double b2 = z.imag;
    
        return String.format("%.2f", ((a1 * a2) - (b1 * b2)) ) + " + " + String.format("%.2f", ((a1 * b2) + (b1 * a2)) ) + "i";
    }    

}