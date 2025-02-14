function insereAjax(xhr){

    var c ='';

    if(xhr.status >= 300){
        c = document.createTextNode('Erreur ' + xhr.status + xhr.responseText);
    } else {
        c = listeChaine(xhr.responseText, "\n");
    }
    
    document.body.appendChild(c);
    
}