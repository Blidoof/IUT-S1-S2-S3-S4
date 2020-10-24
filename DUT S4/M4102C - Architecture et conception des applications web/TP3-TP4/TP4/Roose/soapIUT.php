<?php

$soapClient = new SoapClient('http://iparla.iutbayonne.univ-pau.fr/~roose/wsdl/serveur1.wsdl');

echo($soapClient->retourDate()["serveur"]);
echo($soapClient->retourDate()["date"]);

?>