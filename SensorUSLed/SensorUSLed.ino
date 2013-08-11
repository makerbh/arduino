/*
  Exemplo de utilizacao do sensor ultrassonico HC-SR04
  
  Inspirado em http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/ que, por sua vez
  foi inspirado em  http://goo.gl/kJ8Gl

  Este exemplo acende o led 13 se o objeto esta a menos de DISTANCIA_ALARME cm
  
  Autor: Renato Mintz
  http://www.makerbh.com.br

*/

int PINO_LED = 13;
int PINO_TRIGGER_SENSOR = 12;
int PINO_ECHO_SENSOR = 11;

int DISTANCIA_ALARME = 20;

void setup() {
  pinMode(PINO_TRIGGER_SENSOR, OUTPUT);
  pinMode(PINO_ECHO_SENSOR, INPUT);
  pinMode(PINO_LED, OUTPUT);
}

void loop() {
  long tempoEco, distancia;
  
  //--- gera um pulso no pino trigger do sensor
  digitalWrite(PINO_TRIGGER_SENSOR, LOW);
  delayMicroseconds(2);
  digitalWrite(PINO_TRIGGER_SENSOR, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIGGER_SENSOR, LOW);
  
  //--- le atraso da resposta no pino echo
  tempoEco = pulseIn(PINO_ECHO_SENSOR, HIGH);
  //--- o calculo da distancia considera que a velocidade do som = 343.5 m/s
  distancia = (tempoEco/2) * 0.034;
  
  //--- controla os leds e a campainha de acordo com a distancia
  if (distancia < DISTANCIA_ALARME) {
    digitalWrite(PINO_LED, HIGH);
  }
  else {
    digitalWrite(PINO_LED, LOW);
  }
  
  //--- da um tempo e comeca de novo
  delay(500);
}
