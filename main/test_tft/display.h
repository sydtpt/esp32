#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/FreeSans9pt7b.h>
#define TFT_CS 15
#define TFT_RST 0 // you can also connect this to the Arduino reset
#define TFT_DC 2
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void initDisplay()
{
    tft.initR(INITR_BLACKTAB);    // Initialize the display with the correct driver
    tft.setRotation(0);           // Rotate the screen 90 degrees
    Serial.println("Dinsplay intitialized");
}

void setTemperature(String temperature)
{

    // Set text color and size
    tft.setTextColor(ST77XX_WHITE);
    // tft.setFont(&FreeSansBold9pt7b);
    // Print text
    tft.setCursor(8, 8);
    tft.setTextSize(4);
    tft.print(temperature);
    tft.setCursor(57, 6);
    tft.setTextSize(2);
    tft.print("o");
}

void setHumidity(String humidity)
{
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(8, 42);
  tft.setTextSize(3);
  tft.print(String(humidity) + "%");
}

void setLastWatering(int lastWatering)
{
  tft.fillCircle(12, 80, 5, ST77XX_BLUE);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(22, 72);
  tft.setTextSize(2);
  tft.print(String(lastWatering) +"d");
}

void setLastFertSoil(int lastFertSoil)
{
  tft.fillCircle(12, 120, 5, ST77XX_ORANGE);
  tft.setCursor(22, 114);
  tft.setTextSize(2);
  tft.print(String(lastFertSoil) +"d");
}

void setLastFertLeafs(int lastFertLeafs)
{
  tft.fillCircle(12, 100, 5, ST77XX_GREEN);
  tft.setCursor(22, 94);
  tft.setTextSize(2);
  tft.print(String(lastFertLeafs) +"d");
}

void setSoilHumidity(int humidity_soil) {
  tft.fillRect(106, 8, 16,40, ST77XX_BLUE);
  tft.fillRect(106, 48, 16,80, ST77XX_GREEN);
  tft.fillRect(106, 121, 16,32, ST77XX_ORANGE);
  int y = map(humidity_soil, 30, 100, 154, 8);
  Serial.println(y);
  tft.drawLine(85, y, 102, y, ST77XX_WHITE);
}

void minTempRange(int minTemperature)
{
  tft.fillCircle(10, 145, 3, ST77XX_BLUE);
  tft.setCursor(18, 142);
  tft.setTextSize(1);
  tft.print(minTemperature);
}

void avgTempRange(int avgTemperature)
{
  tft.fillCircle(37, 145, 3, ST77XX_YELLOW);
  tft.setCursor(45, 142);
  tft.setTextSize(1);
  tft.print(avgTemperature);
}


void updateDisplay(String temperature, String humidity, int lastFertSoil, int lastFertLeafs, int lastWatering, long minTemperature, long avgTemperature, int humidity_soil)
{
    tft.fillScreen(ST77XX_BLACK); // Fill the screen with cyan color
    setTemperature(temperature);
    setHumidity(humidity);
    setLastWatering(lastWatering);
    setLastFertLeafs(lastFertLeafs);
    setLastFertSoil(lastFertSoil);
    setSoilHumidity(humidity_soil);
    minTempRange(minTemperature);
    avgTempRange(avgTemperature);
}
