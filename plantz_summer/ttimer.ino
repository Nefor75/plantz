WiFiUDP ntpUDP;
const long utcOffsetInSeconds = 10800;//летнее время
//const long utcOffsetInSeconds = 7200;//зимнее время
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);


void getCarentTime(){
  timeClient.begin();
  timeClient.update();
  Serial.print("Текущее время ");
  Serial.println(timeClient.getFormattedTime());
}

void getTimerLight(int time_off, int time_on){
  
  int current_time = timeClient.getHours()*60+timeClient.getMinutes();
  int hour_on = time_on*60;
  int hour_off = time_off*60;

  if(current_time >= hour_off && current_time <= hour_on){
    digitalWrite(releyLight, LOW);
    Serial.print("Свет не горит т.к текущее время: ");
    Serial.print(current_time);
    Serial.print(" В диапазоне от ");
    Serial.print(hour_off);
    Serial.print(" До ");
    Serial.println(hour_on);
  }else{
    digitalWrite(releyLight, HIGH);
    Serial.print("Свет Горит т.к текущее время: ");
    Serial.print(current_time);
    Serial.print(" Не в диапазоне от ");
    Serial.print(hour_off);
    Serial.print(" До ");
    Serial.println(hour_on);
  }   
}
