<?php
/// Fonction qui envoie une requete au serveur POP3 et lit sa réponse.
/// On met CR et LF après nettoyage de l'argument pour plus de surete.
/// Si l'envoi a échoué ou si la réponse ne commence pas par "+OK",
/// le résultat est False, autrement le resultat est la chaîne qui suit "+OK"
/// (attention elle peut être vide)
function requeter_en_pop ($sock, $req)
{
    if (!fputs($sock, trim($req) . "\r\n")) return false;
    $reponse = fgets($sock);
    return preg_match("@^\+OK(.*)@",$reponse, $m) ? $m[1] : false;
}
?>