/*
 * 
 * Exemple de code pour lire un unique capteur DS18B20 sur un bus 1-Wire.
 # Editeur : bngesp
 # Date   : 2017.04.29
 # Product: Temperature
*/

#ifndef WSNTemperatureSensor_h
#define WSNTemperatureSensor_h

#include <stdlib.h>
#include <stdint.h>
#include <Arduino.h>
#include <OneWire.h>

// constantes

const uint8_t SensorTempPin =  7 ; //le pin ou est branche le capteur




enum DS18B20_RETOURCODES {
  READ_OK,  // Lecture ok
  NO_SENSOR_FOUND,  // Pas de capteur
  INVALID_ADDRESS,  // Adresse reçue invalide
  INVALID_SENSOR  // Capteur invalide (pas un DS18B20)
};

class Temperature
{
public:
	Temperature();
	Temperature(uint8_t sensorPin);
	uint8_t updateTemperature(bool temp);
	float getTemperature();
	void mesureTemperature();

private:
	uint8_t _sensorPin;
	float _sensorvalue;
	OneWire *ds;
		
	
};

#endif