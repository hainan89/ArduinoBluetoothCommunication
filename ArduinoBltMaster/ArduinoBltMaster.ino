// BT Data Logger
// BlueTooth Configuration
/* Include the software serial port library */
#include <SoftwareSerial.h>
/* to communicate with the Bluetooth module's TXD pin */
// HC05 RXD <-> 11
// HC05 TXD <-> 10
#define BT_SERIAL_TX 10
/* to communicate with the Bluetooth module's RXD pin */
#define BT_SERIAL_RX 11
/* Initialise the software serial port */
SoftwareSerial BluetoothSerial(BT_SERIAL_TX, BT_SERIAL_RX);

void setup() {
  Serial.begin(57600);
  /* Set the baud rate for the software serial port */
  BluetoothSerial.begin(57600); // 115200 过高数据传输存在误码率，57600最高Baud
  delay(1000);
  BluetoothSerial.println("Starting ...");
}
char comd;
unsigned long mtime;
String receiveBuf;
void loop() {

  if (BluetoothSerial.available())
  {
    receiveBuf = BluetoothSerial.readString();
    comd = receiveBuf[0];
    Serial.print("Received Data: \t");
    Serial.println(receiveBuf);
  }
  
  if (comd == 'C')
  {
    mtime = millis();
    BluetoothSerial.print("CPU Time: ");
    BluetoothSerial.println(mtime);
    Serial.print("Send Data: \t");
    Serial.println(mtime);
    delay(100);
  }

  if(Serial.available())
  {
    Serial.println(Serial.readString());
  }

}
