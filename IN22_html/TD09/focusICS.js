var incorrect = false;

function memoriseFocus(noeud, regexp) {
    /// memoriser la balise si elle doit re-recevoir le focus
    incorrect = saisieIncorrecte(noeud, regexp);
}

function redonneFocus()
{
    if (incorrect) {
        incorrect.focus();
        /// signaler que c'est fait sinon rique de bouclage
        incorrect = false;
    }
} 