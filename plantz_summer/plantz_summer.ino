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

const char* host = "app.ideassss.space";
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

DHT dhtin(DHTIN, DHTTYPE);
DHT dhtout(DHTOUT, DHTTYPE);

boolean isAutoMode = true;

/*

#define relay D10

*/


ESP8266WebServer server(8080);

void webpage(){
  server.send(200,"text/html", webpageCode);
}

void setup(void) {
  ESP.wdtDisable();//защита от зависаний?
  ESP.wdtEnable(WDTO_8S);//защита от зависаний?
  
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    
  }
  Serial.print("Соединение с ");
  Serial.print(ssid);
  Serial.println(" установлено");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
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
  tempFun();


  delay(100);
 
server.on("/", webpage);
  server.begin();
   /*
  //+++++++++++++++++++++++ START  funExtract ++++++++++++++++++++
  server.on("/", []() {
    server.send(200, "text/html", webPage());
  });
  server.on("/funExtractOn", []() {
    digitalWrite(funExtract, LOW);
    server.send(200, "text/html", webPage());
    delay(100);

  });
  server.on("/funExtractOff", []() {
    digitalWrite(funExtract, HIGH);
    server.send(200, "text/html", webPage());
    delay(100);
    });
    //+++++++++++++++++++++++ END  funExtract ++++++++++++++++++++

    //+++++++++++++++++++++++ START  funIn  ++++++++++++++++++++
  
  server.on("/funInOn", []() {
    digitalWrite(funIn, LOW);
    server.send(200, "text/html", webPage());
    delay(100);
  });
  server.on("/funInOff", []() {
    digitalWrite(funIn, HIGH);
    server.send(200, "text/html", webPage());
    delay(100);
  });
    // +++++++++++++++++++++++ END  funIn ++++++++++++++++++++

    //+++++++++++++++++++++++ START  funHeater  ++++++++++++++++++++

  server.on("/funHeaterOn", []() {
    digitalWrite(funHeater, LOW);
    server.send(200, "text/html", webPage());
    delay(100);
  });
  server.on("/funHeaterOff", []() {
    digitalWrite(funHeater, HIGH);
    server.send(200, "text/html", webPage());
    delay(100);
 });
    // +++++++++++++++++++++++ END  funHeater ++++++++++++++++++++


  //+++++++++++++++++++++++ START  Heater  ++++++++++++++++++++
 
  server.on("/heaterOn", []() {
    digitalWrite(heater, LOW);
    server.send(200, "text/html", webPage());
    delay(100);
  });
  server.on("/heaterOff", []() {
    digitalWrite(heater, HIGH);
    server.send(200, "text/html", webPage());
    delay(100);
  });
    // +++++++++++++++++++++++ END  Heater ++++++++++++++++++++

    //+++++++++++++++++++++++ START  light  ++++++++++++++++++++
 
  server.on("/lightOn", []() {
    digitalWrite(releyLight, HIGH);
    server.send(200, "text/html", webPage());
    delay(100);
  });
  server.on("/lightOff", []() {
    digitalWrite(releyLight, LOW);
    server.send(200, "text/html", webPage());
    delay(100);
  });
    // +++++++++++++++++++++++ END  light ++++++++++++++++++++
    //+++++++++++++++++++++++ START  RESET  ++++++++++++++++++++
    server.on("/resetMC", []() {
    restartMC();
    server.send(200, "text/html", webPage());
    delay(100);
  });
   //+++++++++++++++++++++++ END  RESET  ++++++++++++++++++++
 */ 
  server.begin();
  Serial.println("HTTP server started");
 
}

void loop(void) {
  ESP.wdtFeed();//защита от зависаний?
  
  server.handleClient();

  if(isAutoMode){
    autoMod();
    delay(5000);
  }else{
    manualMode();
  } 
}
