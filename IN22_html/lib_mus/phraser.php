<?php
include "class_sax.php";

function phraser(string $source, preneurs_sax $instance) : mixed
{
	if (!$f = @fopen($source, "r"))
    	return("Impossible de lire '$source'");
    $sax = xml_parser_create();
    xml_set_element_handler($sax,
                            array($instance, 'ouvrante'),
                            array($instance, 'fermante'));
    xml_set_character_data_handler($sax, array($instance, 'texte'));
    xml_parser_set_option($sax, XML_OPTION_CASE_FOLDING, false);
    while ($data = fread($f, 8192)) {
        if (!xml_parse($sax, $data, feof($f))) {
            $data = "Erreur XML :" .
                  xml_error_string(xml_get_error_code($sax)) .
                  " ligne " .
                  xml_get_current_line_number($sax);
            break;
        }
    }
    fclose($f);
    $res = $instance->retour($data);
    xml_parser_free($sax);
    return $res;
}
?>