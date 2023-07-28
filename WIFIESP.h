#include <Arduino.h>
#if defined(ESP8266)
//#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#else
#error "Please check that the microcontroller you are using,can only be used on ESP8266 or ESP32 only"
#endif

class WIFIESP
{
public:
  WIFIESP(const char *ssid, const char *pass);
  int connecting(int loop);
  int connecting(int loop, bool serial);

private:
  const char * _ssid;
  const char * _pass;
  String LED;
  uint64_t Millis;
  bool serial;
};
