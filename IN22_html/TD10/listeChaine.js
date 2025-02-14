function listeChaine(choix, sep){
    var u = document.createElement('ul');

    choix.split(sep).forEach(function(i) {
        if(i) {
            var l = document.createElement('li');
            l.appendChild(document.createTextNode(i));
            u.appendChild(l);
        }
    }) 
    
    return u;
}