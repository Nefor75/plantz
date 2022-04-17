    setInterval(function() {
     $.ajax({                                      
      url: 'DBConnect.php', 
      dataType: 'json',                      
      success: function(data){
 
      var tempin =      data[0];
      var tempout =     data[1];
      var humidityin =  data[2];
      var humidityout = data[3];
      var light =       data[4];
      var releylight =  data[8];
      var funextract =  data[6];
      var funin =       data[5];
      var funwduv=      data[7];
      var funwyduv =    data[9];
      var ipwifi =      data[10];
      
      
       document.getElementById("temp-in").innerHTML      = tempin + " &degС";
       document.getElementById("temp-out").innerHTML     = tempout + " &degС";
       document.getElementById("humidity-in").innerHTML  = humidityin + " %";
       document.getElementById("humidity-out").innerHTML = humidityout + " %";
       document.getElementById("light-status").innerHTML = light;
       document.getElementById("reley-light").innerHTML  = releylight;
       document.getElementById("fun-extract").innerHTML  = funextract;
       document.getElementById("fun-in").innerHTML       = funin;
       document.getElementById("fun-wduv").innerHTML     = funwduv;
       document.getElementById("fun-wyduv").innerHTML    = funwyduv;
    //   document.getElementById("ip-wifi").innerHTML      = ipwifi + " (Ip_WebServer)";

      }
     }, 60000); //при 5000 ругается хостинг на частые запросы
    });