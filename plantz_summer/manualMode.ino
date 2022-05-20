void manualMode(){
     connekt();
  Serial.println("MANUAL MODE");
  pinMode(funExtract, OUTPUT);
  pinMode(funIn, OUTPUT);
  pinMode(funWduv, OUTPUT);
  pinMode(funWYduv, OUTPUT);
  pinMode(releyLight, OUTPUT);
 
}
