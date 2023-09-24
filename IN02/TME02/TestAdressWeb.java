public class TestAdressWeb {
    public static void main(String[] args) {
        AdressWeb adress1 = new AdressWeb("https", "site1.fr", "/dir1/page1.html");
        AdressWeb adress2 = new AdressWeb("site2.fr", "/dir2/page2.html");
        AdressWeb adress3 = new AdressWeb("site3.fr");

        System.out.println("Adress 1 : " + adress1.toString());
        System.out.println("Adress 2 : " + adress2.toString());
        System.out.println("Adress 3 : " + adress3.toString());
    }
}