String webPage() {
  int tempIn = dhtin.readTemperature();
  int tempOut = dhtout.readTemperature();
  int humidityIn = dhtin.readHumidity();
  int humidityOut = dhtout.readHumidity();
  String web;
  web += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/> <meta charset=\"utf-8\"><title>Plantz</title><style>button{color:black;padding: 10px 27px;}</style></head>";
  web += "<h1 style=\"text-align: center;font-family: Open sans;font-weight: 100;font-size: 20px;\">P L A N T Z</h1><div>";

  web += "<div style=\"text-align: center;width: 100px;color: white;padding: 10px 30px;background-color: #304FFE;margin: 0;\">"+ String((int)CONSTTEMP)+"</div>";
  web += "<div style=\"text-align: center;width: 100px;color: white;padding: 10px 30px;background-color: #304FFE;margin: 0;\">"+ String((int)tempIn)+"</div>";
  web += "<div style=\"text-align: center;width: 100px;color: white;padding: 10px 30px;background-color: #304FFE;margin: 0;\">"+ String((int)tempOut)+"</div>";
  web += "<div style=\"text-align: center;width: 100px;color: white;padding: 10px 30px;background-color: #304FFE;margin: 0;\">"+ String((int)humidityIn)+"</div>";
  web += "<div style=\"text-align: center;width: 100px;color: white;padding: 10px 30px;background-color: #304FFE;margin: 0;\">"+ String((int)humidityOut)+"</div>";

  //++++++++++ funExtract  +++++++++++++

  web += "<p style=\"text-align: left;margin-top: 0px;margin-bottom: 5px;margin-left: 70px;\">------funExtract-------</p>";
if (digitalRead(funExtract) == 1) {
  web += "<div style=\"text-align: center;width: 198px;color: white;padding: 10px 30px;background-color: #ec1212;margin: 0;\">OFF</div>";
  }
else {
  web += "<div style=\"text-align: center;width: 198px;color: white;padding: 10px 30px;background-color: #43a209;margin: 0;\">ON</div>";
  }
  web += "<div style=\"text-align: left;margin: 25px 50px;\"> <a href=\"funExtractOn\"><button>ON</button></a>&nbsp;<a href=\"funExtractOff\"><button>OFF</button></a></div>";

  // ++++++++ funExtract +++++++++++++

  //++++++++++ funIn  +++++++++++++

  web += "<p style=\"text-align: center;margin-top: 0px;margin-bottom: 5px;\">----funIn----</p>";
if (digitalRead(funIn) == 1) {
    web += "<div style=\"text-align: center;width: 198px;color: white;padding: 10px 30px;background-color: #ec1212;margin: 0 auto;\">OFF</div>";
  }
else {
    web += "<div style=\"text-align: center;width: 198px;color: white;padding: 10px 30px;background-color: #43a209;margin: 0 auto;\">ON</div>";
  }
  web += "<div style=\"text-align: center;margin: 25px 0px;\"> <a href=\"funInOn\"><button>ON</button></a>&nbsp;<a href=\"funInOff\"><button>OFF</button></a></div>";

  // ++++++++ funIn +++++++++++++


  //++++++++++ funHeater  +++++++++++++

  web += "<p style=\"text-align: center;margin-top: 0px;margin-bottom: 5px;\">----funHeater----</p>";
if (digitalRead(funWduv) == 1) {
    web += "<div style=\"text-align: center;width: 198px;color: white;padding: 10px 30px;background-color: #ec1212;margin: 0 auto;\">OFF</div>";
  }
else {
    web += "<div style=\"text-align: center;width: 198px;color: white;padding: 10px 30px;background-color: #43a209;margin: 0 auto;\">ON</div>";
  }
  web += "<div style=\"text-align: center;margin: 25px 0px;\"> <a href=\"funHeaterOn\"><button>ON</button></a>&nbsp;<a href=\"funHeaterOff\"><button>OFF</button></a></div>";

  // ++++++++ funHeater +++++++++++++


  //++++++++++ Heater  +++++++++++++

  web += "<p style=\"text-align: center;margin-top: 0px;margin-bottom: 5px;\">----Heater----</p>";
if (digitalRead(funWYduv) == 1) {
    web += "<div style=\"text-align: center;width: 198px;color: white;padding: 10px 30px;background-color: #ec1212;margin: 0 auto;\">OFF</div>";
  }
else {
    web += "<div style=\"text-align: center;width: 198px;color: white;padding: 10px 30px;background-color: #43a209;margin: 0 auto;\">ON</div>";
  }
  web += "<div style=\"text-align: center;margin: 25px 0px;\"> <a href=\"heaterOn\"><button>ON</button></a>&nbsp;<a href=\"heaterOff\"><button>OFF</button></a></div>";

  // ++++++++ Heater +++++++++++++

//++++++++++ Light  +++++++++++++

  web += "<p style=\"text-align: center;margin-top: 0px;margin-bottom: 5px;\">----Light----</p>";
if (digitalRead(releyLight) == 0) {
    web += "<div style=\"text-align: center;width: 198px;color: white;padding: 10px 30px;background-color: #ec1212;margin: 0 auto;\">OFF</div>";
  }
else {
    web += "<div style=\"text-align: center;width: 198px;color: white;padding: 10px 30px;background-color: #43a209;margin: 0 auto;\">ON</div>";
  }
  web += "<div style=\"text-align: center;margin: 25px 0px;\"> <a href=\"lightOn\"><button>ON</button></a>&nbsp;<a href=\"lightOff\"><button>OFF</button></a></div>";

  // ++++++++ Light +++++++++++++

  // ========UPDATE=============
  web += "<div style=\"text-align:center;margin-top: 20px;\"> <a href=\"/\"><button style=\"width:250px;\">UPDATE</button></a></div>";
  // ========UPDATE=============

  // ========RESET=============
  web += "<div style=\"text-align:center;margin-top: 20px;\"> <a href=\"resetMC\"><button style=\"width:250px;\">RESET</button></a></div>";
  // ========RESET=============

  web += "</div>";
//  web += "<meta http-equiv="refresh"; content="10";>";
  return (web);
}
