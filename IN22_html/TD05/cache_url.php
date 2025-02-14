<?php

include 'actualiser_cache.php';
include 'fournir_page.php';
include 'limiter_cache.php';
include 'memoriser_cache.php';
include 'trouver_cache.php';
include 'typer_cache.php';
include 'utiliser_cache.php';

define ("MAX_CACHES",);
define ("FILE_CACHE",);
define ("DIR_CACHE",);

$url = empty ($_GET['url'])? '' : $_GET['url'];

$reponse = utiliser_cache($url, DIR_CACHE);

if ($reponse){
    $visit = unserialize(file_get_contents(FILE_CACHE));
    $new_visit = actualiser_cache($visites, $reponse, DIR_CACHE, MAX_CACHES);

    file_put_contents(FILE_CACHE, serialize($new_visit));
}


?>