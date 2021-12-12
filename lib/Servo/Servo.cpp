#include "Servo.h"

Servo::Servo(SMS_STS *servoCtl, int id) : servoCtl(servoCtl), id(id)
{
}

Servo::~Servo()
{
}

void Servo::setCtl(SMS_STS *servoCtl)
{
    this->servoCtl = servoCtl;
}

void Servo::setId(int id)
{
    this->id = id;
}

void Servo::setTarget(int targetDeg) {
    targetPos = targetDeg * DEGTOPOS;
}

void Servo::update(double speedFactor) {
    // this->servo.WritePosEx(1, 4095, 3400, 50); //舵机(ID1)以最高速度V=3400步/秒，加速度A=50(50*100步/秒^2)，运行至P1=4095位置
    servoCtl->WritePosEx(id, targetPos, speedFactor * MAX_SPEED, 100);
}