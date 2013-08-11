/*
  Biblioteca de utilizacao do sensor ultrassonico HC-SR04
  
  Inspirado em http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/ que, por sua vez
  foi inspirado em  http://goo.gl/kJ8Gl

  Autor: Renato Mintz
  http://www.makerbh.com.br

*/
#include "Arduino.h"
#include "SensorUltrassonico.h"

SensorUltrassonico::SensorUltrassonico(int pinoTrigger, int pinoEcho) {
  _pinoTrigger = pinoTrigger;
  _pinoEcho = pinoEcho;
  pinMode(_pinoTrigger, OUTPUT);
  pinMode(_pinoEcho, INPUT);
  _serialPrint = 0;
}

/*
    retorna: distancia em cm
*/
long SensorUltrassonico::medeDistancia() {
  long tempoEco;
  if (_serialPrint) {
    Serial.println("medeDistancia");
  }
  //--- gera um pulso no pino trigger do sensor
  digitalWrite(_pinoTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(_pinoTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(_pinoTrigger, LOW);  
  //--- le atraso da resposta no pino echo
  tempoEco = pulseIn(_pinoEcho, HIGH);
  //--- o calculo da distancia considera que a velocidade do som = 343.5 m/s
  return (tempoEco/2) / 29.1;  
}
  
