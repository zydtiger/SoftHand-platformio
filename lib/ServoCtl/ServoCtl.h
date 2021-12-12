#ifndef _SERVOCTL_H
#define _SERVOCTL_H

#include "Servo.h"

#define FULL 800

class ServoCtl
{
private:
    SMS_STS servoCtl;
    int servoCnt;
    Servo *servos;
public:
    ServoCtl(int servoCnt = 0, HardwareSerial *serial = nullptr);
    ~ServoCtl();
    void turnId(int id, int percentage);
    void resetId(int id);
    void turn(int percentage);
    void reset();
    void update(double speedFactor = 0.5);
};

#endif
