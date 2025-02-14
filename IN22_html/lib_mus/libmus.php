<?php

error_reporting(E_ALL);

if ($_POST)
{
  header('Content-Type: text/plain');
  echo $_POST['search'] . "#" . $_POST['type'];

  include 'libmus.setcookies.php';
  libmus_setcookies($_POST['search'], $_POST['type']);
}
else {
?>

<!DOCTYPE html PUBLIC '-//W3C//DTD XHTML Basic 1.1//EN'
    'http://www.w3.org/TR/xhtml-basic/xhtml-basic11.dtd'>
<html xmlns='http://www.w3.org/1999/xhtml' lang='fr'>
  <head>
    <meta http-equiv='Content-Type' content='text/html;charset=utf-8' />
    <link href="libmus.css" rel="stylesheet" type="text/css" />
    <style type="text/css">
    table.albums { border-collapse: collapse;}
    table.albums th, table.albums.td { padding: 20px;}
    </style>
    <title>Librairie musicale</title>
    
  </head>
  <body onload='libmus_event();'>
    <div id='title'> 
      <h1>La médiathèque</h1>
    </div>
    <div id='recherche'>
    <form action='' method='post' onsubmit='return libmus_ajax(this);'>
      <fieldset>
        <label for='search'>Recherche :</label>
        <input type='text' id='search' name='search' />
        <label for='type'> par </label>
        <select id='type' name='type'>
          <option value='album'>Album</option>
          <option value='artiste'>Artiste</option>
        </select>
        <input type='submit' value='Soumettre' />
      </fieldset>
    </form>
    </div>
    <div id='historique'>
      <button onclick='libmus_historique();'>Afficher l'historique de recherche</button>
      <ul id='hist-liste'>
      </ul>
    </div>
    <table id='albums' class='albums'>
      <?php 
        include 'libmus.sax.php';
        include 'libmus.table.php';
            include 'libmus.liste.php';
            echo libmus_table(phraser('libmus.xml', new libmus_sax));?>
    </table>
    <script type='text/javascript' src='libmus.event.js'></script>
    <script type='text/javascript' src='libmus.xhr.js'></script>
    <script type='text/javascript' src='libmus.ajax.js'></script>
    <script type='text/javascript' src='ajax.js'></script>
    <script type='text/javascript' src='libmus.historique.js'></script>
  </body>
</html>

<?php
}
?>
