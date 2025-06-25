#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <SPIFFS.h>

const char* ssid = "DeneyapWiFi";
const char* password = "sifre12345";

AsyncWebServer server(80);


void clicked(){
  Serial.println("Butona Basıldı!");
  }


void setup() {
  Serial.begin(9600);
  
  // SPIFFS'i başlat
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS başlatılamadı!");
    return;
  }
  
  // Access Point modunu başlat
  WiFi.softAP(ssid, password);
  Serial.println("Access Point başlatıldı.");
  Serial.print("IP Adresi: ");
  Serial.println(WiFi.softAPIP()); 
  
  // Kök URL için index.html dosyasını sun
  server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");
  
  // /buton URL'sine gelen GET isteğini işle
  server.on("/buton", HTTP_GET, [](AsyncWebServerRequest *request){
  clicked();
  request->send(200, "text/plain", "Buton tıklandı!");
  });
  
  // Sunucuyu başlat
  server.begin();
  Serial.println("Web sunucusu başlatıldı.");
}

void loop() {
}
