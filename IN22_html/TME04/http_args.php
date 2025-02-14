<?php

function http_args($nom = '', $tab = array(), $version = ''){

    if($version < 1) return "\r\n";

    if($version > 1) $tab[] = "Host: $nom";

    return "HTTP/$version\r\n". join("\r\n", $tab). "\r\n\r\n";
}



?>