void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
}

void onWifiConnect(const WiFiEventStationModeGotIP& event) {
  Serial.println("Connected to Wi-Fi sucessfully.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Level Wi-Fi signal: ");
  Serial.println(WiFi.RSSI());
}

void onWifiDisconnect(const WiFiEventStationModeDisconnected& event) { 
  Serial.println("Disconnected from Wi-Fi, trying to connect..."); 
  WiFi.disconnect();
  WiFi.begin(ssid, password);
}

 
