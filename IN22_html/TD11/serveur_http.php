<?php
class serveur_http {
    public $status;
    public $url;
    public $path;
    public $queryString;
    public $ressource;
    public $type_mime;
    public $AUTH_USER;
    public $REQUEST_METHOD;
    public $REMOTE_ADDR;
    public $conf;
    public $site ='';
    public $port = 0;

    function __construct($conf)
    {
        $this->conf = $conf;
    }

    function service($url)
    {
        $this->url = $url;
        try {
			include "http_url.php"; http_url($this);
  			include "http_auteur.php"; http_auteur($this);
   			include "http_chemin.php"; http_chemin($this);
   			include "http_controle.php"; http_controle($this);
   			include "http_mime.php"; http_mime($this);
   			include "http_reponse.php"; http_reponse($this);
        }
        catch(Exception $e) {
            $this->status = $e->getMessage();
            header("HTTP/1.1 ". $this->status);
            echo $this->status, "\n";
        }
        include "http_log.php"; http_log($this);
    }
}
/*// Test
(new serveur_http(array('Hosts' =>
            array('127.0.0.1' => array(80 => '/Library/WebServer/Documents/'))))
)->service('http://127.0.0.1/Essai/index.html.en');
//*/
?>
