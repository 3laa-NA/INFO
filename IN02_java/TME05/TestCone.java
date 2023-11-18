public class TestCone {
    public static void main(String[] args) {
        System.out.println("le nombre de cones crees : " + Cone.nbCones());

        Cone cone1 = new Cone(5.0, 10.0);
        Cone cone2 = new Cone();

        System.out.println("le nombre de cones crees : " + Cone.nbCones());

    }
}
