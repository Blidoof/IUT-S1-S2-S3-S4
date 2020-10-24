<?php

$soapClient = new SoapClient("http://localhost/serveur12.wsdl");

echo($soapClient->retourDate()["serveur"]);

 ?>
