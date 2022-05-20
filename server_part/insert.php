<?php

if(isset($_GET["tempIn"],
         $_GET["tempOut"],
         $_GET["humidityIn"],
         $_GET["humidityOut"],
         $_GET["light"],
         $_GET["releyLight"],
         $_GET["funExtract"],
         $_GET["funIn"],
         $_GET["funWduv"],
         $_GET["funWYduv"],
         $_GET["wifi_ip_to_string"]
        )) {
   $tempin      = $_GET["tempIn"]; 
   $tempout     = $_GET["tempOut"];
   $humidityin  = $_GET["humidityIn"]; 
   $humidityout = $_GET["humidityOut"];
   $fotolight   = $_GET["light"];
   $ip_wifi     = $_GET["wifi_ip_to_string"];
   $releylight  = ($_GET["releyLight"]==1) ? "ON" : "OFF";
   $funextract  = ($_GET["funExtract"]==0) ? "ON" : "OFF";
   $funin       = ($_GET["funIn"]==0) ? "ON" : "OFF";
   $funwduv     = ($_GET["funWduv"]==0) ? "ON" : "OFF";
   $funwyduv    = ($_GET["funWYduv"]==0) ? "ON" : "OFF";
/*
   $imgfotosensoron   = "<img src='assets/fotosensor_green.jpg'>";
   $imgfotosensoroff   = "<img src='assets/fotosensor_white.jpg'>";
   $imgfotosensor   = ($_GET["light"]=="ON") ? $imgfotosensoron : $imgfotosensoroff;
*/
   $servername = "intui2.mysql.ukraine.com.ua";
   $username = "intui2_app";
   $password = "2P-s&6uy7H";
   $dbname = "intui2_app";

   // Create connection
   $conn = new mysqli($servername, $username, $password, $dbname);
   // Check connection
   if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
   }

   $sql = "UPDATE plants1 SET TemperatureIn=$tempin,TemperatureOut=$tempout,HumidityIn=$humidityin,HumidityOut=$humidityout,Light='$fotolight',ReleyLight='$releylight',FunExtract='$funextract',FunIn='$funin',FunWduv='$funwduv',FunWYduv='$funwyduv',Ip_Wifi='$ip_wifi'";

  if ($conn->query($sql) == TRUE) {
      echo "New record created successfully";
  } else {
      echo "Error: " . $sql . " => " . $conn->error;
  }

   $conn->close();
} else {
  echo "temperature is not set";
}
?>