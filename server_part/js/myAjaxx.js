    setInterval(function() {
     $.ajax({                                      
      url: 'DBConnect.php', 
      dataType: 'json',                      
      success: function(data){
 
      var tempin =      data[0];
      var tempout =     data[1];
      var humidityin =  data[2];
      var humidityout =   data[3];
      var light =         data[4];
      var releylight =    data[8];
      var funextract =    data[6];
      var funin =         data[5];
      var funwduv=        data[7];
      var funwyduv =      data[9];
      var ipwifi =        data[10];
      //var imgfotosensor = data[11];
      
    //   var block = document.getElementById('fotosensor_img');
      
       document.getElementById("temp-in").innerHTML      = tempin + " &degС";
       document.getElementById("temp-out").innerHTML     = tempout + " &degС";
       document.getElementById("humidity-in").innerHTML  = humidityin + " %";
       document.getElementById("humidity-out").innerHTML = humidityout + " %";
       document.getElementById("light-status").innerHTML = light;
       
       //chimgfoto(light-status);
       //document.getElementById('fotosensor').innerHTML = "url('/assets/fotosens_green.jpg')";
       //while(light == 'ON')
     //  block.style.backgroundImage = "url('/assets/fotosens_green.jpg')";
       //if(light != 'ON')
          //block.backgroundImage = "url('/assets/fotosens_green.jpg').innerHTML";
          //block.style.backgroundImage= "url('/assets/fotosens_img_on.jpg').innerHTML";
     // else 
          // block.style.backgroundImage = "url('/assets/fotosens_img_off.jpg').innerHTML";
    


       document.getElementById("reley-light").innerHTML  = releylight;
       document.getElementById("fun-extract").innerHTML  = funextract;
       document.getElementById("fun-in").innerHTML       = funin;
       document.getElementById("fun-wduv").innerHTML     = funwduv;
       document.getElementById("fun-wyduv").innerHTML    = funwyduv;
    //   document.getElementById("ip-wifi").innerHTML      = ipwifi + " (Ip_WebServer)";

      }
     }, 60000); //при 5000 ругается хостинг на частые запросы
    });
    
    function chimgfoto(id){
        var block = document.getElementById('fotosensor_img').innerHTML;
        var e = document.getElementById(id);
        var txt = e.textContent || e.innerText;
        if(txt == "ON")
        block.style.backgroundImage = "url('/assets/fotosens_img_on.jpg')";
    }
   
   function chimgfans(id){
        var block = document.getElementById('fan_vduw_on');
        if(id == "ON")
        block.style.backgroundImage = "url('/assets/fan_on.jpg').innerHTML";
    }
    