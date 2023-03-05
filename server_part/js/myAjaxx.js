    setInterval(function() {
     $.ajax({                                      
      url: 'DBConnect.php', 
      dataType: 'json',                      
      success: function(data){
 
      var tempin =           data[0];
      var tempout =          data[1];
      var humidityin =       data[2];
      var humidityout =      data[3];
      var light =            data[4];
      var releylight =       data[8];
      var funextract =       data[6];
      var funin =            data[5];
      var funwduv=           data[7];
      var funwyduv =         data[9];
      var ipwifi =           data[10];
      var imgfotosensor =    data[11];
      var imgcolwduv =       data[12];
      var imgcolwyduv =      data[13];
      var imgcolin =         data[14];
      var imgcolexist =      data[15];
      var imglamp =          data[16];
      var releyheater =      data[17];
      var imgheater =        data[18];
     // var consttemp =        data[17];
      //var consttimligstart = data[18];
      //var constTimligstop =  data[19];
      //var constcolcheck =    data[20];
      
    //   document.getElementById("constant_temp_var").innerHTML = consttemp + " &degС";
    //   document.getElementById("start_timer_light_var").innerHTML = consttimligstart + ":00";
    //   document.getElementById("stop_timer_light_var").innerHTML  = consttimligstop + ":00";
    //   document.getElementById("interval_check_sens_var").innerHTML = constcolcheck + " min";
    
  //   *******************sensors DHT-22*************************************    
       document.getElementById("temp-in").innerHTML      = tempin + " &degС";
       document.getElementById("temp-out").innerHTML     = tempout + " &degС";
       document.getElementById("humidity-in").innerHTML  = humidityin + " %";
       document.getElementById("humidity-out").innerHTML = humidityout + " %";
       
    //   *******************fotosensor*************************************
       document.getElementById("light-status").innerHTML = light;
       document.getElementById("fotosensor_img").setAttribute("style", "background-image: url('"+imgfotosensor+"');");

    //   ***********************RELEYLIGHT**************************************
       document.getElementById("reley-light").innerHTML  = releylight;
       document.getElementById("lamp_image").setAttribute("style", "background-image: url('"+imglamp+"');");
       
    //   *********************heater********************************************
       document.getElementById("heater").innerHTML  = releyheater;
       document.getElementById("img_heater").setAttribute("class", imgheater);

    //   *********************funextract********************************************
       document.getElementById("fun-extract").innerHTML  = funextract;
       document.getElementById("img-fun-extract").setAttribute("class", imgcolexist);

    //   *********************funin********************************************
       document.getElementById("fun-in").innerHTML       = funin;
       document.getElementById("img_cooler_in").setAttribute("class", imgcolin);

    //   *********************funwduv********************************************
       document.getElementById("fun-wduv").innerHTML     = funwduv;
       document.getElementById("img_cooler_wduv").setAttribute("class", imgcolwduv);
//alert(imgcolwyduv);
    //   *********************funwyduv********************************************
       document.getElementById("fun-wyduv").innerHTML    = funwyduv;
       document.getElementById("img_fun-wyduv").setAttribute("class", imgcolwyduv);

    // document.getElementById("ip-wifi").innerHTML      = ipwifi + " (Ip_WebServer)";
      }
     }, 60000); //при 5000 ругается хостинг на частые запросы
    });
    