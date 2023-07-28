#include "WIFIESP.h"


WIFIESP::WIFIESP(const char *ssid, const char *pass)
{
  Serial.begin(115200);
  _ssid = ssid; 
  _pass = pass;
}

int WIFIESP::connecting(int loop)
{
  Serial.println("");
  Serial.print("Connecting");
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(_ssid, _pass);
  int status = WiFi.status();
  while (status != WL_CONNECTED)
  {
    delay(50);
    if (millis() - Millis >= 1000)
    {
      loop--;
      if (loop == 0)
      {
        ESP.restart();
      }
      status = WiFi.status();
      Serial.print(".");
      Millis = millis();
    }
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(_ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  return status;
}

int WIFIESP::connecting(int loop, bool serial)
{
  if (serial)
  {
    delay(1000);
    Serial.println("");
    Serial.print("Connecting");
  }
  int status = WiFi.status();
  while (status != WL_CONNECTED)
  {
    delay(50);
    if (millis() - Millis >= 1000)
    {
      loop--;
      if (loop == 0)
      {
        ESP.restart();
      }
      status = WiFi.status();
      if (serial)
        Serial.print(".");

      Millis = millis();
    }
  }
  if (serial)
  {
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(_ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  return status;
}