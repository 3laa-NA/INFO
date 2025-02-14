function submitInAjax(form) {
    var saisies = 0;
    var qs = new Array;
    /// form.elements est une collection, pas un tableau donc forEach pas dispo.
    /// On simule le foreach de PHP ce qui impose de contrôler la présence de value.
    /// L'autre solution est trop lourde:
    /// Array.prototype.forEach.call(form.elements, function(v) ....
    for (var k in form.elements) {
        var v = form.elements[k];
        if (v.name && v.value &&
            (((v.type != 'checkbox') && (v.type != 'radio'))
             || v.checked)) {
            qs[saisies] = v.name + '=' + v.value;
            ++saisies;
        }
    }
    if (!saisies) {
        alert('Au moins une saisie');
        return false;
    }

    /// pour être compatible avec le formulaire
    /// on prend la methode HTTP indiquee dans l'attribut method.
    /// Attention la DTD le veut en minuscule, et le RFC HTTP en majuscule
    /// Selon sa valeur, la QS est mise dans le flux d'entrée où à la fin de l'URL
    if (form.method == 'post')
         return !ajax(form.action, qs.join('&'), insereAjax, 'POST');
    else return !ajax(form.action + '?' + qs.join('&'), '', insereAjax, 'GET');
} 