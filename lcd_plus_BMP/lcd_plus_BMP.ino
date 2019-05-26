
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <LiquidCrystal.h>

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

int interval = 3000;
LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

void setup() { 
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));
  
  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
}
  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print("BMP280 & LCD1602");
  lcd.setCursor(1, 1);
  lcd.print("Weatherstation");

  delay(interval*3);
  lcd.clear();
}
void loop() {
//    Serial.print(F("Temperature = "));
//    Serial.print(bmp.readTemperature());
//    Serial.println(" *C");
//    Serial.print(F("Pressure = "));
//    Serial.print(bmp.readPressure());
//    Serial.println(" Pa");

//    Serial.print(F("Approx altitude = "));
//    Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
//    Serial.println(" m");

//    Serial.println();
//    delay(2000);

  lcd.setCursor(2, 0);
  lcd.print("Temperature");
  lcd.setCursor(5, 1);
  lcd.print(bmp.readTemperature(),1);
  lcd.print(" C");

 delay(interval);
 lcd.clear();

  lcd.setCursor(3,0);
  lcd.print("Pressure");
  lcd.setCursor(2,1);
  lcd.print(bmp.readPressure());
  lcd.print(" hPa");
  
 delay(interval);
 lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Approx alt = ");
  lcd.setCursor(2,1);
  lcd.print(bmp.readAltitude(1013.25));
  lcd.print(" m");

 delay(interval);
 lcd.clear();
}
