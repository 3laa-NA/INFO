import java.util.ArrayList;

public class Etudiant {
    private final String nom;
    public static ArrayList<Etudiant> listEtudiants = new ArrayList<Etudiant>();
    private int[] list_notes;
    private int cmpt=0;

    public Etudiant(String nom){
        this.nom=nom;
        list_notes=new int [5];
        listEtudiants.add(this);
    }

    public String toString() {
        String res=nom + " ";
        for(int i=0 ;i<cmpt ; i++){
            res += list_notes[i] +" ";
        }
        return res;
    }

    public void entrerNote(int note) throws TabNotesPleinException{
        if(cmpt==5){
            throw new TabNotesPleinException("le tableau de notes de l'etudiant " + nom + " est plein");
        }else{
            list_notes[cmpt] = note;
            cmpt++;
        }
    }

}
