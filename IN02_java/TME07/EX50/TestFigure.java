public class TestFigure {
    public static void main(String[] args) {
        
        Carre ca1 = new Carre(5);
        Cercle cer1 = new Cercle(5);

        Figure2D[] tab1 = new Figure2D[2];

        tab1[0]=ca1;
        tab1[1]=cer1;

        for (Figure2D x : tab1){
            System.out.println("Surface : " + x.surface() + " Perimetre : " + x.perimetre());
        }
    }
}
