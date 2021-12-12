#include <BreathingLED.h>
#include <BLE.h>
#include <stdlib.h>
#include <Arduino.h>
#include <Buzzer.h>
#include <ServoCtl.h>

// 定义外部中断的Mode
// 0: 无中断，读取Touch值
// 1：Touch中断，执行 TouchEvent()
// 2: 外部IO的中断
// #define EXT_ISR_MODE 2

BreathingLED *led;
Buzzer *buzzer;
ServoCtl *servoCtl;
BLE *ble;

void setup()
{
  // start serial
  Serial.begin(115200);
  // servo control serial
  Serial2.begin(1000000);

  // init peripherals
  led = new BreathingLED(LED(18, 19, 21, 22), 2000);
  buzzer = new Buzzer(26, 25, 27);
  servoCtl = new ServoCtl(5, &Serial2);

  // wait to connect to ble
  led->getRawLED()->bAnalog(255);
  ble = new BLE("Awesome Hand ESP32");
  buzzer->beepFor(2);

  ble->waitForConnection();
  buzzer->beepFor(3);

  led->setColor(0, 255, 0);
}

void loop()
{
  led->update();
  servoCtl->update();

  if (!ble->isConnected()) {
    buzzer->beepFor(1);
    led->getRawLED()->bAnalog(255);
    ble->waitForConnection();
  }

  if (ble->isAvailable())
  {
    std::string cmd = ble->getRecv();
    Serial.println(String(cmd.c_str()));

    if ('1' <= cmd[0] && cmd[0] <= '5')
      servoCtl->turnId(cmd[0]-'0', atoi(cmd.substr(2).c_str()));
    else if (cmd[0] == '0')
      servoCtl->turn(atoi(cmd.substr(2).c_str()));
    else if (cmd[0] == 'g') {
      servoCtl->turnId(1,100);
      servoCtl->turnId(4,100);
      servoCtl->turnId(5,100);
    }
  }
}