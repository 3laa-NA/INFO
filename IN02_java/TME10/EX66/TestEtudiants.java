public class TestEtudiants {
    public static void main(String[] args) {

        //boolean b=false;
        Etudiant etu = null;
        
        for(String str : args){
            
            try{

                int note = Integer.parseInt(str);
                if(etu!=null){
                    etu.entrerNote(note);
                } 

            }catch(NumberFormatException e){
                etu = new Etudiant(str);
            }catch(TabNotesPleinException e){
                System.out.println(e.getMessage());
            }
        }
        
        System.out.print("les " + Etudiant.listEtudiants.size() + " étudiants :\n[");

        for (Etudiant e : Etudiant.listEtudiants){
            if(e!=null){
                System.out.print(e.toString() + ";");
            }
        }
        System.err.println("]");
    }   
}
