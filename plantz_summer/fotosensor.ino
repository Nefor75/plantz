String fotoCheck(int fotosens){
   String light = ""; 
  if(fotosens < 300){ 
      Serial.print("Фотодатчик показывает свет включен ");
      light = "ON";
    }else{
      Serial.print("Фотодатчик показывает темно ");
      light = "OFF";    
    }
      Serial.println(light);
      return(light); 
  }
