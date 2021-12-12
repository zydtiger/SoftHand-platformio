#ifndef _BUZZER_H
#define _BUZZER_H

#include "Arduino.h"

class Buzzer
{
private:
    int freq, pin;
    bool curStatus = 0;
    long lastUpdate = -1;

public:
    Buzzer(int pin, int VCC = -1, int GND = -1, int freq = 1000);
    ~Buzzer();
    void buzzFor(int ms);
    void beepFor(int times, int t_each = 100, int t_gap = 100);
};


#endif