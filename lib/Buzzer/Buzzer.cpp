#include "Buzzer.h"

Buzzer::Buzzer(int pin, int VCC, int GND, int freq) : freq(freq), pin(pin)
{
  pinMode(pin, OUTPUT);

  if (GND != -1)
  {
    pinMode(GND, OUTPUT);
    digitalWrite(GND, LOW);
  }

  if (VCC != -1)
  {
    pinMode(VCC, OUTPUT);
    digitalWrite(VCC, HIGH);
  }
}

Buzzer::~Buzzer()
{
}

void Buzzer::buzzFor(int ms)
{
  int now = millis();
  while (millis() - now < ms)
  {
    digitalWrite(pin, HIGH);
    delayMicroseconds(1e6 / freq / 2);
    digitalWrite(pin, LOW);
    delayMicroseconds(1e6 / freq / 2);
  }
}

void Buzzer::beepFor(int times, int t_each, int t_gap) {
  while (times--) {
    this->buzzFor(t_each);
    delay(t_gap);
  }
}