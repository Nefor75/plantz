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
        //  $_GET["constTemp"],
        //  $_GET["constTimLigStart"],
        //  $_GET["constTimLigStop"],
        //  $_GET["constColCheck"]
        )) {
    //   $consttemp = $_GET["constTemp"];
    //   $consttimligstart = $_GET["constTimLigStart"];
    //   $constTimligstop  = $_GET["constTimLigStop"];
    //   $constcolcheck  = $_GET["constColCheck"];

   $tempin      = $_GET["tempIn"]; 
   $tempout     = $_GET["tempOut"];
   $humidityin  = $_GET["humidityIn"]; 
   $humidityout = $_GET["humidityOut"];
   
   //***********************  fotosens**********************
   $fotolight   = "";
   $url_img_foto = "";
   $temp_foto_img  = $_GET["light"];
   if($temp_foto_img == "ON"){
       $fotolight   = "ON";
       $url_img_foto = "assets/fotosens_img_on.jpg";
   }else {
       $fotolight   = "OFF";
       $url_img_foto = "assets/fotosens_img_off.jpg";
   }
  
   //***********************releylight**********************
   //$releylight  = ($_GET["releyLight"]==1) ? "ON" : "OFF";
   $url_img_light = "";
   $releylight  = "";
   $temp_img_light = $_GET["releyLight"];
   if($temp_img_light == 1){
       $releylight  = "ON";
       $url_img_light = "assets/lamp_on.jpg";
    }else{
           $releylight  = "OFF";
       $url_img_light = "assets/lamp_off.jpg";
        }
       
   //***********************  funExtract**********************
   $url_img_coller_funextract = "";
   $temp_funextract = $_GET["funExtract"];
   $funextract = "";
      if($temp_funextract == 0){
          $funextract = "ON";
          $url_img_coller_funextract = "fun-extract_img-rotate";
      }else{
          $funextract = "OFF";
          $url_img_coller_funextract = "fun-extract_img";
            }
   
   //***********************  funIn**********************
   $url_img_coller_in = "";
   $temp_funin = $_GET["funIn"];
   $funin = "";
      if($temp_funin == 0){
          $funin = "ON";
          $url_img_coller_in = "fun-in_img_fan-rotate";
      }else{
          $funin = "OFF";
          $url_img_coller_in = "fun-in_img_fan";
      }
   
 //***********************  funWduv**********************
   $url_img_coller_wduv = "fan-wduv-img";
   $temp_funWduv = $_GET["funWduv"];
   $funwduv = "";
      if($temp_funWduv == 0){
          $funwduv = "ON";
          $url_img_coller_wduv = "fan-wduv-img-rotate";
      }else{
          $funwduv = "OFF";
          $url_img_coller_wduv = "fan-wduv-img";
      }
      
  //***********************  funWYduv**********************    
  $url_img_coller_wyduv = "";
  $temp_funWyduv = $_GET["funWYduv"];
  $funwyduv = "";
      if($temp_funWyduv == 0){
          $funwyduv = "ON";
          $url_img_coller_wyduv = "fun-wyduv-img-rotate";
      }else{
          $funwyduv = "OFF";
          $url_img_coller_wyduv = "fun-wyduv-img";
      }

   $ip_wifi     = $_GET["wifi_ip_to_string"];

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

   $sql = "UPDATE plants1 SET TemperatureIn=$tempin,TemperatureOut=$tempout,HumidityIn=$humidityin,HumidityOut=$humidityout,Light='$fotolight',ReleyLight='$releylight',FunExtract='$funextract',FunIn='$funin',FunWduv='$funwduv',FunWYduv='$funwyduv',Ip_Wifi='$ip_wifi',UrlFotosensor='$url_img_foto',UrlImgColWduv='$url_img_coller_wduv',UrlImgColWyduv='$url_img_coller_wyduv',UrlImgColIn='$url_img_coller_in',UrlImgColExtract='$url_img_coller_funextract',UrlLightImg='$url_img_light'";
//   ConstTemp=$consttemp,ConstTimLigStart=$consttimligstart,ConstTimLigStop=$consttimligstop,ConstColCheck=$constcolcheck";

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