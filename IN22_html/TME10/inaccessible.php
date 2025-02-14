<?php

define('DIR_TRACE', '/tmp/');
    
/// Calcul du nom du fichier

function cookie_file ($cpl='')
{
    return md5($cpl . $_SERVER['REMOTE_ADDR'] . $_SERVER['HTTP_USER_AGENT']);
}

$fichier = DIR_TRACE . 'trace_' . cookie_file() . '.txt';

/// si pas de données
/// c'est une demande de lecture du fichier puis destruction
if (!$_GET) {
    header('Content-Type: text/plain');
    if (is_readable($fichier)) {
        readfile($fichier);
	    unlink($fichier);
    } else {
        echo "Pas de trace\n";
    }
} else {
    $trace = $_GET['left'] . ' ' . $_GET['top'];
    $f = file_put_contents($fichier, $trace . "\n", FILE_APPEND);
    if ($f) {
        header('HTTP/1.1 204 No Content');
    } else {
        header('HTTP/1.1 403 Forbidden');
        header('Content-Type: text/plain; charset=utf-8');
        echo "Fichier $fichier inaccessible en écriture\n";
    }
}
?>
