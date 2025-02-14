<?php

//true si on garde

function limiter_cache($entetes){
    if( isset($entetes["Expires"]) AND strtotime($entetes["Expires"][0]) > time()) return false;

    return true;
}


?>