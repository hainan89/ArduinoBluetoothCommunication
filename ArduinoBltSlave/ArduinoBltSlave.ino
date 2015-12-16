#include <SoftwareSerial.h>

// HC05 RXD <-> 11
// HC05 TXD <-> 10
SoftwareSerial BTSerial(10, 11); // RX | TX

void setup()
{
  Serial.begin(57600);  // Arduino 的串口波特率设置，需要和Blt模块的波特率设置一致， 否则通过串口调试助手发送的AT指令无法识别
  //Serial.println("Enter AT commands:");
  BTSerial.begin(57600);  //// 115200 过高数据传输存在误码率，57600最高Baud
}

char sendChar;
char receiveChar;
void loop()
{

  // Keep reading from Arduino Serial Monitor and send to HC-05
  while(Serial.available())
  {
    sendChar = Serial.read();
    BTSerial.print(sendChar);
    Serial.print(sendChar);
  }
  
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  while(BTSerial.available())
  {
    receiveChar = BTSerial.read();
    Serial.print(receiveChar);
  }

  
    
}
