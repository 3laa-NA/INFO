<?php
function debut_html ($title, $headers=array())
 {
  $link_and_styles = '';
  foreach ($headers as $k => $header) {
      $atts = is_numeric($k) ? '' : " media='$k'";
      if (!is_array($header)) {
          /// Si pas un sous-tableau avec cet index,
          /// on considere que la valeur est le contenu d'une balise Style,
          $link_and_styles .= "<style type='text/css'$atts>$header</style>\n";
      } else {
          /// valeurs par defaut:
          if (!isset($header['rel'])) {
              $header['rel'] = 'stylesheet';
              if (!isset($header['type']))
                  $header['type'] = 'text/css';
          }
          foreach ($header as $k => $v) $atts .= " $k='$v'";
          $link_and_styles .= "<link$atts />\n";
      }
  }
  return
    "<!DOCTYPE html PUBLIC '-//W3C//DTD XHTML Basic 1.1//EN'
        'http://www.w3.org/TR/xhtml-basic/xhtml-basic11.dtd'>\n" .
    "<html xmlns='http://www.w3.org/1999/xhtml' lang='fr'>\n" .
    "<head>\n" .
    "<meta http-equiv='Content-Type' content='text/html;charset=utf-8' />\n" .
    "<title>" . 
    $title .
    "</title>\n" .
    $link_and_styles .
    "</head>\n";
}

/*// Test
echo debut_html('CSS',
array(
  'a{color:red}',
  'print' => 'a{color:black}',
  array('href' => 'allmedia.css'),
  'screen' => array('href' => 'screen.css'),
  array('href' => 'spip.png', 'rel' => 'shortcut icon', 'type' => 'image/png'),
  array('href' => 'atom.php', 'rel' => 'alternate', 'type' => 'application/rss+xml'))
)
//*/

?>