Deneyap Kart Access Point Web Kontrol Paneli
Bu proje, Deneyap Kart (ESP32-S2 tabanlı) üzerinde bir Access Point (AP) oluşturarak bir web kontrol paneli sunar. Panelde bir buton bulunur ve butona tıklandığında seri monitörde "Butona basıldı" mesajı yazdırılır.

Özellikler

Deneyap Kart, "DeneyapWiFi" adında bir WiFi ağı oluşturur.
Web tarayıcısında http://192.168.4.1 adresine gidilerek erişilen bir kontrol paneli.
Butona tıklandığında seri monitörde mesaj yazdırılır ve tarayıcıda bir uyarı gösterilir.

Gereksinimler

Donanım: Deneyap Kart .
Yazılım:
Arduino IDE.
ESP32FS eklentisi (SPIFFS için).
ESPAsyncWebServer ve AsyncTCP kütüphaneleri.
ESP32 kart desteği (Arduino IDE’ye eklenmiş olmalı).



Kurulum

Kütüphaneleri Yükleyin:

Arduino IDE’de “Tools > Manage Libraries” menüsünden ESPAsyncWebServer ve AsyncTCP kütüphanelerini yükleyin.
ESP32FS eklentisini kurun.


Arduino Kodunu Yükleyin:

Deneyap-AP-WebControl.ino dosyasını Arduino IDE’de açın.
“Tools” menüsünden Deneyap Kart’ı seçin ve doğru portu belirleyin.
Kodu karta yükleyin.


HTML Dosyasını SPIFFS’e Yükleyin:

data/index.html dosyasını proje klasörünüzde bir data klasörüne kaydedin.
Arduino IDE’de “Tools > ESP32 Sketch Data Upload” seçeneğini kullanarak index.html dosyasını SPIFFS’e yükleyin.


Test Edin:

Seri monitörü açın (9600 baud).
Telefon veya bilgisayardan “DeneyapWiFi” ağına bağlanın (şifre: sifre12345).
Tarayıcıda http://192.168.4.1 adresine gidin.
“Buton” butonuna tıklayın; seri monitörde “Butona basıldı” mesajını ve tarayıcıda “Buton tıklandı!” uyarısını görün.



Dosya Yapısı
Deneyap-AP-WebControl/
├── Deneyap-AP-WebControl.ino  # Arduino kodu
├── data/
│   └── index.html            # Web kontrol paneli
├── README.md                 # Proje açıklaması
