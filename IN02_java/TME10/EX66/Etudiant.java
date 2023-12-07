public class Etudiant {
    private final String nom;
    private int[] list_notes;
    private int cmpt=0;

    public Etudiant(String nom){
        this.nom=nom;
        list_notes=new int [5];
    }

    public String toString() {
        String res=nom + ", notes : ";
        for(int x :list_notes){
            res += x +", ";
        }
        return res;
    }

    public void entrerNote(int note) throws TabNotesPleinException{
        if(cmpt==5){
            throw TabNotesPleinException();
        }else{
            list_notes[cmpt] = note;
            cmpt++;
        }
    }

}
