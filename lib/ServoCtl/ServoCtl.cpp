#include "ServoCtl.h"

ServoCtl::ServoCtl(int servoCnt, HardwareSerial *serial) : servoCnt(servoCnt)
{
    servoCtl.pSerial = serial;

    servos = new Servo[servoCnt + 1];
    for (int i = 1; i <= servoCnt; i++)
    {
        servos[i].setCtl(&servoCtl);
        servos[i].setId(i);
    }
}

ServoCtl::~ServoCtl()
{
    delete servos;
}

void ServoCtl::update(double speedFactor) {
    for (int i=1;i<=servoCnt;i++) servos[i].update(speedFactor);
}

void ServoCtl::turnId(int id, int percentage)
{
    servos[id].setTarget(percentage * FULL / 100.);
}

void ServoCtl::resetId(int id)
{
    turnId(id, 0);
}

void ServoCtl::turn(int percentage)
{
    for (int i = 1; i <= servoCnt; i++)
        turnId(i, percentage * FULL / 100.);
}

void ServoCtl::reset()
{
    turn(0);
}