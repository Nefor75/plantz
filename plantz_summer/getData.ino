void connekt(){
    int tempIn = dhtin.readTemperature();
    int tempOut = dhtout.readTemperature();
    int humidityIn = dhtin.readHumidity();
    int humidityOut = dhtout.readHumidity();
    int foto = analogRead(PHOTO_SENSOR);
    String light = fotoCheck(foto);
    int readFunExtract = digitalRead(funExtract);
    int readFunIn = digitalRead(funIn);
    int readFunWduv = digitalRead(funWduv);
    int readFunWYduv = digitalRead(funWYduv);
    int readReleyLight = digitalRead(releyLight);

  if (!client.connect(host, port)) {
    Serial.println("Нет соединения с хостом");
    delay(2000);
    return;
  }
    client.print("GET /insert.php?");
    client.print("tempIn=");
    client.print(tempIn);
    client.print("&tempOut=");
    client.print(tempOut);
    client.print("&humidityIn=");
    client.print(humidityIn);
    client.print("&humidityOut=");
    client.print(humidityOut);
    client.print("&light=");
    client.print(light);
    client.print("&releyLight=");
    client.print(readReleyLight);
    client.print("&funExtract=");
    client.print(readFunExtract); 
    client.print("&funIn=");
    client.print(readFunIn); 
    client.print("&funWduv=");
    client.print(readFunWduv);
    client.print("&funWYduv=");
    client.print(readFunWYduv);
    client.println(" HTTP/1.1");
    client.print( "Host: " );
    client.println(host);
    client.println( "Connection: close" );
    client.println();
    client.println();
    client.stop();                        
  }
