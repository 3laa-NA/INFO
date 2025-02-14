function bouger(noeud){
    var t = Math.ceil(Math.random()*(window.innerHeight-75));
    var l = Math.ceil(Math.random()*(window.innerWidth-75));
    noeud.style.top = t + "px";
    noeud.style.left= l + "px";
    noeud.style.opacity /= 2;
    ajax("inaccessible.php?left="+l+"&top=" + t);
    clearTimeout(next);
}

function merci(noeud) {
    clearTimeout(next);
    document.getElementById('non').style='opacity:.9'
    c = document.createTextNode("Merci d'avoir dit " + noeud.firstChild.data);
    document.getElementById('titre').appendChild(c);
    ajax("inaccessible.php", '', insereAjax);
}

function reveille()
{
    next = setTimeout(function() {
	    var id = document.getElementById('titre');
	    var n = parseFloat(id.style.fontSize) * 1.5;
	    id.style.fontSize = n + 'em';
            reveille();},
		   5000);
}

function insereAjax(xhr) {
    var c = (xhr.status >= 300) ?
        ('Retour HTTP inattendu ' + xhr.status + xhr.responseText + "\n") :
        listeChaine(xhr.responseText, "\n");
    document.body.appendChild(c);
}

function listeChaine(choix, sep) {
    var u = document.createElement('ul');
    choix.split(sep).forEach(function(i) {
	if (i) {
	    var l = document.createElement('li');
	    l.appendChild(document.createTextNode(i));
	    u.appendChild(l);
	}
    })
    return u;
}
