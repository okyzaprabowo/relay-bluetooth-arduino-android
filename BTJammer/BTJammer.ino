#include <SoftwareSerial.h>// import the serial library

SoftwareSerial ChannelHC05(10, 11); // RX, TX
#define JAMMER_PIN 13
#define MASK_PIN 12

int BluetoothData;

void setup() {
  // put your setup code here, to run once:
  ChannelHC05.begin(9600);
  ChannelHC05.println(digitalRead(JAMMER_PIN));
  pinMode(JAMMER_PIN,OUTPUT);
  pinMode(MASK_PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (ChannelHC05.available()) {
    BluetoothData=ChannelHC05.read();
    
    if(BluetoothData=='3'){
      digitalWrite(JAMMER_PIN,1);
      digitalWrite(MASK_PIN,1);
      ChannelHC05.println("JAMMER ON, MASK ON ");
    }

    if(BluetoothData=='1'){
      digitalWrite(JAMMER_PIN,0);
      digitalWrite(MASK_PIN,1);
      ChannelHC05.println("JAMMER OFF, MASK ON ");
    }

    if(BluetoothData=='2'){
      digitalWrite(JAMMER_PIN,1);
      digitalWrite(MASK_PIN,0);
      ChannelHC05.println("JAMMER ON, MASK OFF ");
    }
   
    if (BluetoothData=='0'){
      digitalWrite(JAMMER_PIN,0);
      digitalWrite(MASK_PIN,0);
      ChannelHC05.println("JAMMER OFF, MASK OFF ");
    }
  }
delay(100);// prepare for next data ...
}
