<?php

/// phpinfo() sur les machines de la PPTI fournit cette année:
///  8.1.22 2
/// date  Aug 15 2023 09:52:21 

/// 2e partie
include 'debut_html.php';
/// charger la fonction tableau_en_table
include '/home/alaana/INFO-main/IN22_html/TD02/tableau_en_table.php';
echo debut_html("Informations sur le serveur");
/// et visualiser la super globale
echo tableau_en_table($_SERVER, 'Informations sur le serveur');
 
?>