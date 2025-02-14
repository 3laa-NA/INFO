/// url: ressource sur le serveur courant
/// flux: flux d'entrée en cas de methode POST
/// rappel: fonction à appliquer sur l'objet Ajax au retour
/// method: methode HTTP (GET par defaut)
function ajax(url, flux, rappel, method) {
    var r = window.XMLHttpRequest ? new XMLHttpRequest() :
      (window.ActiveXObject ?  new ActiveXObject("Microsoft.XMLHTTP") : '');
    if (!r) return false;
    if (rappel) r.onreadystatechange = function () {rappel(r);}
    r.open(method ? method : 'GET', url, true);
    if (flux)
	r.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    r.send(flux);
    return true;
}
