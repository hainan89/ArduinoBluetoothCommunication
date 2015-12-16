#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup()
{
  Serial.begin(115200);  // Arduino 的串口波特率设置，需要和Blt模块的波特率设置一致， 否则通过串口调试助手发送的AT指令无法识别
  //Serial.println("Enter AT commands:");
  BTSerial.begin(115200);  // HC-05 default speed in AT command more
}

char sendChar;
char receiveChar;
void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  while(BTSerial.available())
  {
    receiveChar = BTSerial.read();
    Serial.print(receiveChar);
  }

  // Keep reading from Arduino Serial Monitor and send to HC-05
  while(Serial.available())
  {
    sendChar = Serial.read();
    BTSerial.print(sendChar);
    Serial.print(sendChar);
  }
    
}
