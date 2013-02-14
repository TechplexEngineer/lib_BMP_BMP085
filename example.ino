/* BMP085 Extended Example Code
  by: Jim Lindblom
  SparkFun Electronics
  date: 1/18/11
  license: CC BY-SA v3.0 - http://creativecommons.org/licenses/by-sa/3.0/
  
  Get pressure and temperature from the BMP085 and calculate altitude.
  Serial.print it out at 9600 baud to serial monitor.

  Update (7/19/11): I've heard folks may be encountering issues
  with this code, who're running an Arduino at 8MHz. If you're 
  using an Arduino Pro 3.3V/8MHz, or the like, you may need to 
  increase some of the delays in the bmp085ReadUP and 
  bmp085ReadUT functions.
*/
#include <Wire.h>
#include "BMP085.h"

short temperature;
long pressure;

void setup()
{
  Wire.begin();
  BP.Begin();
  Serial.begin(9600);
  Serial.print("Plexuino Starting Up!\n");
  delay(1000);
}

void loop()
{
  temperature = BP.GetTemperature(BP.ReadUT());
  pressure = BP.GetPressure(BP.ReadUP());
  Serial.print("Temperature: ");
  Serial.print(temperature*0.1, DEC);
  Serial.println(" deg C");
  Serial.print("Pressure: ");
  Serial.print(pressure, DEC);
  Serial.println(" Pa");
  Serial.println();
  delay(1000);
}


