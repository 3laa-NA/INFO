<?php
session_start();
include 'phraser.php';
include 'ebout.nav.php';
$catalogue = phraser('ebout.xml', new ebout_sax);
$categories = $catalogue[0];
$articles = $catalogue[1];
if ($_GET OR $_POST) {
    if ($_POST) {
        include 'ebout.query.php';
        header('Content-Type: text/plain');
        echo ebout_query($articles, !!$_POST);
    } else {
        if (isset($_GET['panier']) AND is_array($_GET['panier'])) {
            foreach($_GET['panier'] as $id_article => $quantite) {
                $quantite = intval($quantite); // sécuriser la saisie
                if ($quantite > 0)
                    $_SESSION['panier'][$id_article] = $quantite;
                else unset($_SESSION['panier'][$id_article]);
            }
        }
        include 'ebout.session.php';
        $res = ebout_session($articles);
        if (isset($_GET['fin'])) {
            $_SESSION = array();
        }
        echo $res;
    }
    exit;
}
?>
<!DOCTYPE html PUBLIC '-//W3C//DTD XHTML Basic 1.1//EN'
    'http://www.w3.org/TR/xhtml-basic/xhtml-basic11.dtd'>
<html xmlns='http://www.w3.org/1999/xhtml' lang='fr'>
  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <link href="ebout.css" rel="stylesheet" type="text/css" />
    <link href="ebout.nav.css" rel="stylesheet" />
    <style type="text/css"> </style>
    <title>Boutique en ligne</title>
  </head>
  <body>
   <div class="wrapper">
     <h1>Prêt à porter, chaussures et accessoires</h1>
     <?php echo ebout_nav($categories);?>
     <form action='' class='main'>
		<div><input name="fin" type='submit' value='Passer commande' />
              pour <span class='total'>        </span>
	    </div>  
        <div id='liste'></div>
	 </form>
   </div>
   <script type='text/javascript' src='ebout.options.js'></script>
   <script type='text/javascript' src='ebout.ajax.post.js'></script>
   <script type='text/javascript' src='ebout.ajax.get.js'></script> 
   <script type='text/javascript' src='ajax.js'></script>
  </body>
</html>
