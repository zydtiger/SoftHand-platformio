#ifndef _SERVO_H
#define _SERVO_H

#include "Arduino.h"
#include "SCServo.h"

const double DEGTOPOS = 4095/360.;
const int MAX_SPEED = 3400;

class Servo
{
private:
    int targetPos = 0;
    SMS_STS *servoCtl;
    int id;
public:
    Servo(SMS_STS *servoCtl = nullptr, int id = 1);
    ~Servo();
    void setCtl(SMS_STS *servoCtl);
    void setId(int id);
    void setTarget(int targetDeg);
    void update(double speedFactor);
};


#endif