function controlCreneau(){

    var e = form.elements;
    var t = false;

    t ||= saisieIncorrecte(e['debut'],re_heure);
    t ||= saisieIncorrecte(e['fin'],re_heure);
    t ||= saisieIncorrecte(e['jour'],re_jour);
    t ||= saisieIncorrecte(e['ICS'],/./);

    if(t){
        alert("Saisies incorrectes");
        return false;
    } else {
        if (e['fin'].value < e['debut'].value) {
            alert('debut > fin')
            return false; // en DOM pur:  event.preventDefault();
        }
    }
    return true;
}