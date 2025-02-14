<?php

define('RE_HTTP_STATUS', '@^(?:HTTP/(\S*)\s+)?(\d+)@');

/*//
if (preg_match(RE_HTTP_STATUS, '200', $m)) var_dump($m); else echo "KO";
if (preg_match(RE_HTTP_STATUS, 'HTTP/1.1 302', $m)) var_dump($m); else echo "KO";
//*/

?>