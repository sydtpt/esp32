#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/FreeSans9pt7b.h>
#define TFT_CS     15
#define TFT_RST    0  // you can also connect this to the Arduino reset
                      // in which case, set this #define pin to 0!
#define TFT_DC     2

// Initialize the display
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  tft.initR(INITR_BLACKTAB); // Initialize the display with the correct driver
  tft.fillScreen(ST77XX_BLACK); // Fill the screen with cyan color
  tft.setRotation(2); // Rotate the screen 90 degrees


  // Draw a red rectangle
  // tft.drawRect(10, 10, 100, 60, ST77XX_WHITE);

  // Draw a green filled circle
  // tft.fillCircle(80, 80, 30, ST77XX_RED);

  // Set text color and size
  tft.setTextColor(ST77XX_WHITE);
 // tft.setFont(&FreeSansBold9pt7b);
  // Print text
  tft.setCursor(8, 8);
  tft.setTextSize(4);
  tft.print("20");
  tft.setCursor(58, 6);
  tft.setTextSize(2);
  tft.print("o");



  // tft.setFont(&FreeSans9pt7b);
  tft.setCursor(8, 42);
  tft.setTextSize(3);
  tft.print("60%");

  delay(5000); // Wait for 5 seconds
}

void loop() {
  // Your loop code here
}
