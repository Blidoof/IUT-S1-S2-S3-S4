<HTML> <BODY>
<?php
session_start();

if (isset($_SESSION['login']) && isset($_SESSION['password'])) {
  echo "<center><h1>Bourse de wall street</h1></center>";

  echo '<center><img src="http://localhost/ficbourse.php" alt="Oui"/></center>';
  echo '<a href="./logout.php"> Déconnection</a>';
}
else {
  "Vous n'êtes pas connecté. Merci de vous recommencer en vous connectant !";
}


 ?>
</BODY> </HTML>
