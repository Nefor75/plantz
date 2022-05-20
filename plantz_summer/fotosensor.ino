/* 
 
  String fotoCheck(int fotosens){
 Serial.println(fotosens);
    String llight = (fotosens < 300) ? "Светит" : "Не светит"; 
    Serial.println(llight);
    
    return(llight);
  }

 */
   
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
