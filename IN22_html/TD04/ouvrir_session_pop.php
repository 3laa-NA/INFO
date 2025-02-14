<?php
/// Fonction de connexion pour serveur POP3
/// Timeout de 5 secondes (300s en std)
function ouvrir_session_pop ($server, $user, $pass, $port=110)
{
    $sock = @fsockopen($server, $port, $errno, $errstr, 5);
    if ($sock == false){
        return "Erreur de connexion au serveur POP [$errno] : $errstr\n";
    } else {
        /// Chercher le message de bienvenue du serveur
        $reponse = fgets($sock);
        /// Envoi de la requete USER et contrôle
        if (requeter_en_pop($sock,"USER $user") === false)
            return "USER $user inconnu\n";
        /// Envoi de la requete PASS et contrôle
        if (requeter_en_pop($sock,"PASS $pass") === false)
            return "PASS incorrect\n";
        /// L'utilisateur est reconnu
        /// on retourne le descripteur
        return $sock;
    }
}
?>