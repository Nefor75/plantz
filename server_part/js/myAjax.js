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
      
      
       document.getElementById("temp-in").innerHTML      = tempin + " &degС (Температура внутри)";
       document.getElementById("temp-out").innerHTML     = tempout + " &degС (Температура снаружи)";
       document.getElementById("humidity-in").innerHTML  = humidityin + " % (Влажность внутри)";
       document.getElementById("humidity-out").innerHTML = humidityout + " % (Влажность снаружи)";
       document.getElementById("light-status").innerHTML = light + " (Статус освещ.(датчик))";
       document.getElementById("reley-light").innerHTML  = releylight + " (Состояние реле)";
       document.getElementById("fun-extract").innerHTML  = funextract + " (Кулер - вытяжной)";
       document.getElementById("fun-in").innerHTML       = funin + " (Кулер - внутренний)";
       document.getElementById("fun-wduv").innerHTML     = funwduv + " (Кулер - вдув)";
       document.getElementById("fun-wyduv").innerHTML    = funwyduv + " (Кулер - вЫдув)";

      }
     }, 60000); //при 5000 ругается хостинг на частые запросы
    });