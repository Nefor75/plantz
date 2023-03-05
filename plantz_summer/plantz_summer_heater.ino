#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <DHT.h>
#include "webPageCode.h";

WiFiClient client;

#ifndef STASSID
#define STASSID "Waflya"
#define STAPSK  "raikkonen"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

//const char* host = "app.ideassss.space";
const char* host = "2173003.intui.web.hosting-test.net";
const uint16_t port = 80;

#define PHOTO_SENSOR A0

#define DHTIN D6
#define DHTOUT D8
#define DHTTYPE DHT22

#define funExtract D2
#define funIn D3
#define funWduv D5 // кулер вдув
#define funWYduv D4 // кулер вЫдув
#define releyLight D11
#define releyHeater D10

DHT dhtin(DHTIN, DHTTYPE);
DHT dhtout(DHTOUT, DHTTYPE);

boolean isAutoMode = true;

WiFiEventHandler wifiConnectHandler;
WiFiEventHandler wifiDisconnectHandler;

ESP8266WebServer server(8080);

void webpage(){
  server.send(200,"text/html", webpageCode);
}

void setup(void) {
//  ESP.wdtDisable();//защита от зависаний?
//  ESP.wdtEnable(WDTO_8S);//защита от зависаний?
  
  Serial.begin(115200);

  wifiConnectHandler = WiFi.onStationModeGotIP(onWifiConnect);
  wifiDisconnectHandler = WiFi.onStationModeDisconnected(onWifiDisconnect);
  initWiFi();
    
  dhtin.begin();
  dhtout.begin();

  pinMode(funExtract, OUTPUT);
  digitalWrite(funExtract, LOW);
  pinMode(funIn, OUTPUT);
  digitalWrite(funIn, LOW);
  pinMode(funWduv, OUTPUT); //-----------------------вдув
  digitalWrite(funWduv, HIGH);
  pinMode(funWYduv, OUTPUT); //-----------------------вЫдув
  digitalWrite(funWYduv, HIGH);
  pinMode(releyLight, OUTPUT);
  pinMode(releyHeater, OUTPUT);
  digitalWrite(releyHeater, LOW);
  tempFun();

  delay(100);
 
  server.on("/", webpage);
  server.begin();
 
  Serial.println("HTTP server started");
 
}

void loop(void) {
  
  server.handleClient();

  if(isAutoMode){
    delay(5000);
    autoMod();
    //delay(5000);
  }else{
    manualMode();
  } 
}
