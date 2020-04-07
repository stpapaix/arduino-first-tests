#include <LiquidCrystal_I2C.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 12
OneWire oneWire (ONE_WIRE_BUS);
DallasTemperature sensors (&oneWire);

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup(void)
{
  lcd.init();
  lcd.backlight();
}

void loop ()
{
  sensors.requestTemperatures();
  float x=sensors.getTempCByIndex(0);

  lcd.setCursor (0,0);
  lcd.print ("Test Temperature");
  lcd.setCursor (0,2);
  lcd.print ("T=");
  lcd.setCursor (3,2);
  lcd.print (x);
}
