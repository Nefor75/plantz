unsigned long timing; // Переменная для хранения точки отсчета для интервала опроса оборудования
void coolerCheck(int minuten){
   if (millis() - timing > minuten*60000){ // 60000 это минута 
      timing = millis(); 
      tempFun(); 
      Serial.print("Следующий опрос датчиков через ");
      Serial.print(minuten);
      Serial.println(" мин");  
   }
}

void tempFun(){
  int tempin = dhtin.readTemperature();
  int tempout = dhtout.readTemperature();
  int humidityIn = dhtin.readHumidity();
  int humidityOut = dhtout.readHumidity();
  
    
    Serial.println();
    Serial.print("Температура внутреннего датчика ");
    Serial.print(tempin);
    Serial.println(" *C");
    Serial.print("Влажность внутреннего датчика ");
    Serial.print(humidityIn);
    Serial.println(" %");
    Serial.println();
    Serial.print("Температура внешнего датчика ");
    Serial.print(tempout);
    Serial.println(" *C");
    Serial.print("Влажность внешнего датчика ");
    Serial.print(humidityOut);
    Serial.println(" %");
    Serial.println();
    Serial.print("Константа = ");
    Serial.print(CONSTTEMP);
    Serial.println(" *C");

      int readFunExtract = digitalRead(funExtract);
      int readFunIn = digitalRead(funIn);
      int readFunWduv = digitalRead(funWduv); 
      int readFunWYduv = digitalRead(funWYduv);
   
     //   digitalWrite(funExtract, LOW);//кулер включен т.к. контакты ненормально разомкнуты
     // Serial.println();
      Serial.print("Вытяжной кулер ВКЛ ");      
      Serial.println(readFunExtract); 
      Serial.print("Внутренний кулер ВКЛ ");
       // digitalWrite(funIn, LOW);
      Serial.println(readFunIn); 
      Serial.println();
      
       if (tempin < CONSTTEMP && tempin > tempout){  
        digitalWrite(funWduv, HIGH);
        digitalWrite(funWYduv, HIGH);
      Serial.println("funWduv ВЫКЛ ");     
      Serial.print("funWYduv ВЫКЛ ");    
      Serial.println();
      Serial.println("Внутри температура ниже константы, а снаружи холодно, поэтому кулеры не работают(нагреваем бокс)");//1
  }
      else if (tempin < CONSTTEMP && tempin < tempout){  
        digitalWrite(funWduv, LOW);
        digitalWrite(funWYduv, HIGH);
      Serial.println("funWduv ВКЛ ");
      Serial.print("funWYduv ВЫКЛ ");
      Serial.println();
      Serial.println("Внутри температура ниже константы, а снаружи тепло, поэтому с улицы гонит воздух");//2   
  } 
      else if (tempin < CONSTTEMP && tempin == tempout){  
        digitalWrite(funWduv, HIGH);
        digitalWrite(funWYduv, HIGH);
      Serial.println("funWduv ВЫКЛ ");
      Serial.print("funWYduv ВЫКЛ ");
      Serial.println();
      Serial.println("Внутри температура ниже константы, а снаружи равна с внутри, поэтому кулеры не работают(нагреваем бокс)");//3
  } 
      else if (tempin == CONSTTEMP){  
        digitalWrite(funWduv, HIGH);
        digitalWrite(funWYduv, HIGH);
      Serial.println("funWduv ВЫКЛ ");
      Serial.print("funWYduv ВЫКЛ ");
      Serial.println();
      Serial.println("Внутри температура равна константе, поэтому кулеры не работают");//4
 }
 else if (tempin > CONSTTEMP && tempin > tempout){  
        digitalWrite(funWduv, LOW);
        digitalWrite(funWYduv, HIGH);
      Serial.println("funWduv ВКЛ ");
      Serial.print("funWYduv ВЫКЛ ");
      Serial.println();
      Serial.println("В боксе жарко, а снаружи холодно, поэтому кулер работает на вдув");//5
  }
  else if (tempin > CONSTTEMP && tempin == tempout){  
        digitalWrite(funWduv, HIGH);
        digitalWrite(funWYduv, LOW);
      Serial.println("funWduv ВЫКЛ ");
      Serial.print("funWYduv ВКЛ ");
      Serial.println();
      Serial.println("В боксе жарко, и снаружи жарко, поэтому кулер работает на выдув");//6
  }
  else if (tempin > CONSTTEMP && tempin < tempout){  
        digitalWrite(funWduv, HIGH);
        digitalWrite(funWYduv, LOW);
      Serial.println("funWduv ВЫКЛ ");
      Serial.print("funWYduv ВКЛ ");
      Serial.println();
      Serial.println("В боксе жарко, и снаружи жарко, поэтому кулер работает на выдув");//7
  }
}
