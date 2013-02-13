/*
  BarometricPressure.h - Library for BMP085 Barometric Pressure sensor.
	Created by Blake Bourque, 2/7/13
*/
#ifndef BarometricPressure_h
#define BarometricPressure_h

#include "Arduino.h"

#define BMP085_ADDRESS 0x77  // I2C address of BMP085

const unsigned char OSS = 0;  // Oversampling Setting

class BarometricPressure
{
  public:
  	BarometricPressure(int dumb);
  	void Calibration();
		short GetTemperature(unsigned int ut);
		long GetPressure(unsigned long up);
		unsigned int ReadUT();
		unsigned long ReadUP();
	private:
		char Read(unsigned char address);
		int ReadInt(unsigned char address);
//     Morse(int pin);
//     void dot();
//     void dash();
//   private:
//     int _pin;
};
	

#endif