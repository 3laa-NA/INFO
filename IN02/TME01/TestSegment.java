public class TestSegment {
    public static void main(String[] args) {
        // Création des segments
        Segment segment1 = new Segment(6, 8);
        Segment segment2 = new Segment(12, 5);

        // Calcul des longueurs des segments
        int longueurSegment1 = segment1.longueur();
        int longueurSegment2 = segment2.longueur();

        // Comparaison des longueurs et affichage du résultat
        if (longueurSegment1 > longueurSegment2) {
            System.out.println("Le premier segment est plus long.");
        } else if (longueurSegment1 < longueurSegment2) {
            System.out.println("Le deuxième segment est plus long.");
        } else {
            System.out.println("Les deux segments ont la même longueur.");
        }
    }
}
