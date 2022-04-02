void autoMod(){
Serial.println("AUTO MODE");
  getCarentTime();
  getTimerLight(8,14);
  coolerCheck(1);
  connekt();

}
