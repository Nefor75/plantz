void autoMod(){
Serial.println("AUTO MODE");
  getCarentTime();
  getTimerLight(7,13);
  coolerCheck(5);
  connekt();
}
