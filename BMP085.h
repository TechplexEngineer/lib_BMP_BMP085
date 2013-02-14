/*
  BarometricPressure.h - Library for BMP085 Barometric Pressure sensor.
	Created by Blake Bourque, 2/7/13
*/
#ifndef BarometricPressure_h
#define BarometricPressure_h

#include <Arduino.h>

#define BMP085_ADDRESS 0x77  // I2C address of BMP085

const unsigned char OSS = 0;  // Oversampling Setting

class BarometricPressure
{
  public:
  	BarometricPressure(void);
  	void Begin(void);
  	void Calibration(void);
		short GetTemperature(unsigned int ut);
		long GetPressure(unsigned long up);
		unsigned int ReadUT(void);
		unsigned long ReadUP(void);
	private:

		char Read(unsigned char address);
		int ReadInt(unsigned char address);
	
		// Calibration values
		int ac1;
		int ac2; 
		int ac3; 
		unsigned int ac4;
		unsigned int ac5;
		unsigned int ac6;
		int b1; 
		int b2;
		int mb;
		int mc;
		int md;

		// b5 is calculated in bmp085GetTemperature(...), this variable is also used in bmp085GetPressure(...)
		// so ...Temperature(...) must be called before ...Pressure(...).
		long b5;
};

extern BarometricPressure BP;

#endif