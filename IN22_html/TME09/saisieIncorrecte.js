function saisieIncorrecte(input, re)
{
    var t = re ? re.test(input.value) : true;
    if (saisieIncorrecte.counter === undefined) {
        saisieIncorrecte.counter = 1;
    }
    if (t) {
        input.classList.remove('erreur');
    } else {
        var s = document.querySelectorAll('style')[0].sheet.cssRules.item(0);
        s.style.setProperty('border-width', (++saisieIncorrecte.counter) +'px')
        input.classList.add('erreur');
    }
    return !t;
} 