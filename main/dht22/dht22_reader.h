#include <DHT.h>
#define DHTTYPE DHT22 // DHT 22 (AM2302)
#define DHTPIN 4
DHT dht(DHTPIN, DHTTYPE);

void initDHT()
{
  dht.begin();
}

String getTemperature()
{
  delay(1000);
  float newT = dht.readTemperature(false);
  if (isnan(newT))
  {
    Serial.println("Failed to read from DHT sensor!");
    return "XX";
  }
  return (String)(int)newT;
}

String getHumidity()
{
  delay(1000);
  float newH = dht.readHumidity();
  if (isnan(newH))
  {
    Serial.println("Failed to read from DHT sensor!");
    return "XX";
  }
  return (String)(int)newH;
}
