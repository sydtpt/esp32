
#include "test_tft/display.h"
#include "dht22/dht22_reader.h"
#include "soil/soil_reader.h"


void setup() {
  Serial.begin(9600);
  delay(500); // Wait for 5 seconds

  initDisplay();
  delay(500); // Wait for 5 seconds

  initDHT();
  Serial.print("Setup");
}

void loop() {
  String temperature = getTemperature();
  String humidty = getHumidity();
  int humidity_soil = getSoilHumidity();


  int lastFertSoil = 20;
  int lastFertLeafs = 5;
  int lastWatering = 8;
  int minTemperature = 9;
  int avgTemperature = 13;

  delay(1000); // Wait for 5 seconds
  updateDisplay(temperature,humidty,lastFertSoil,lastFertLeafs,lastWatering,minTemperature,avgTemperature, humidity_soil);
}
