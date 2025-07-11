#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define screen dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Define OLED reset pin (can be -1 if not connected)
#define OLED_RESET    -1

// Create display object using I2C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Initialize serial monitor
  Serial.begin(115200);
  
  // Start I2C communication on custom pins
  Wire.begin(0, 14);  // SDA = GPIO0 (D3), SCL = GPIO14 (D5)
  
  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3C for most OLEDs
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);  // Don't proceed, loop forever
  }

  display.clearDisplay();

  // Display some text
  display.setTextSize(2);             // Text size
  display.setTextColor(SSD1306_WHITE);        // Text color
  display.setCursor(0, 10);           // Position
  display.println("Hello,");
  display.setCursor(0, 35);
  display.println("World!");
  
  display.display();                  // Show on OLED
}

void loop() {
  // Nothing here
}
