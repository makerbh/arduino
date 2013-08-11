/*
  Biblioteca de utilizacao do sensor ultrassonico HC-SR04
  
  Inspirado em http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/ que, por sua vez
  foi inspirado em  http://goo.gl/kJ8Gl

  Autor: Renato Mintz
  http://www.makerbh.com.br

*/
#ifndef SensorUltrassonico_h
#define SensorUltrassonico_h

#include "Arduino.h"

class SensorUltrassonico {
	public:
		SensorUltrassonico(int pinoTrigger, int pinoEcho);
		long medeDistancia();
		void serialPrint(int serialPrint);
		
	private:
		int _pinoTrigger;
		int _pinoEcho;
		int _serialPrint;
};

#endif