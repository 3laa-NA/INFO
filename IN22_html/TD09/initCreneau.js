function initCreneau()
{
    var f = document.querySelectorAll('form')[0].elements;
    // variante: documents.forms[0].elements
    f['jour'].value = date8Chiffres();
    f['debut'].value = 120000;
    f['fin'].value = 130000;

    f['jour'].addEventListener('blur', function() {memoriseFocus(f['jour'], re_jour);})
    
    f['debut'].addEventListener('blur', function() {memoriseFocus(f['debut'], re_heure);})

    f['fin'].addEventListener('blur', function() {memoriseFocus(f['fin'], re_heure);})

    f['ICS'].addEventListener('change', function() {memoriseFocus(f['ICS'], '');})

    f['debut'].addEventListener('focus', redonneFocus);
    f['fin'].addEventListener('focus', redonneFocus);
    f['ICS'].addEventListener('focus', redonneFocus);
    f['jour'].focus();
} 