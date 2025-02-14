<?php
/// Noter l'homonymie sur Aix (Aix-La-Chappelle en Allemagne et beaucoup d'autres en France)
/// et la présence d'apostrophes dans certains noms.

$destinations = 
    array(
        "Europe de l'Ouest" => array(
            "Allemagne" => array("Aix" =>100,"Berlin" => 200, "Munich" =>210, "Dresde" =>150),
            "France" => array("Aix" => 10, "Paris" => 20, "Les Sables d'Olonne" =>30),

            "Italie" => array("Venise" => 100, 'Rome' => 200, 'Naples' => 300),
        ),
        "Europe de l'Est" => array(
            "Roumanie" => array("Bucarest" =>100,"Timisoara" => 200),
            "Ukraine" => array("Kiev" => 500, "Odessa" => 600),
        ),
        "Asie" => array(
            "Japon" => array("Tokyo" => 1000, "Kyoto" => 900, 'Nagoya' => 850),
            "Vietnam" => array("Saïgon" => 870, "Hanoï" => 780, "Đà Nẵng" => 600)
        ),
        "Afrique" => array(
            "Afrique du Sud" =>  array("Prétoria" => 950, "Le Cap" => 800),
            "Côte d'Ivoire" =>  array("Yamoussoukro" => 650, "Abidjan" => 700),
        )
    );
?>