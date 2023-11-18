public class TestVehicule {
    public static void main(String[] args) {
        
    Velo velo1 = new Velo("MyVTT",17);

    System.out.println(velo1.toString());

    velo1.transporter("Paris","Lyon");

    velo1.rouler(10);

    Voiture voit1 = new Voiture("MyVTT",50,5);
   
    System.out.println(voit1.toString());

    voit1.transporter(5,200);

    voit1.approvisionner(40);

    voit1.transporter(7,200);

    voit1.transporter(5,200);

    Camion cam1 = new Camion("MyVTT",70,500);

    System.out.println(cam1.toString());

    cam1.transporter("tuiles",500);

    cam1.approvisionner(40);

    cam1.transporter("tuiles",500);

    Vehicule[] tab = new Vehicule[3];
    tab[0] = velo1;
    tab[1] = voit1;
    tab[2] = cam1;

    for (Vehicule x : tab){
        x.rouler(10);
    }

    }
}
    
