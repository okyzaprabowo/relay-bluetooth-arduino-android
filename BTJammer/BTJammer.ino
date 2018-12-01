#include <SoftwareSerial.h>// import the serial library

SoftwareSerial ChannelHC05(10, 11); // RX, TX

// Relay IN
#define JAMMER_PIN 2
#define MASK_PIN 3
#define FRAME_PIN 4

int BluetoothData;

void setup() {
  // put your setup code here, to run once:
  ChannelHC05.begin(9600);
  ChannelHC05.println(digitalRead(JAMMER_PIN));
  pinMode(JAMMER_PIN,OUTPUT);
  pinMode(MASK_PIN,OUTPUT);
  pinMode(FRAME_PIN,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (ChannelHC05.available()) {
    BluetoothData=ChannelHC05.read();
    
    if(BluetoothData=='1'){
      digitalWrite(JAMMER_PIN,0);
      ChannelHC05.println("JAMMER OFF ");
      Serial.println("JAMMER OFF ");
    }

    if(BluetoothData=='0'){
      digitalWrite(JAMMER_PIN,1);
      ChannelHC05.println("JAMMER ON ");
      Serial.println("JAMMER ON ");
    }

    if(BluetoothData=='3'){
      digitalWrite(MASK_PIN,0);
      ChannelHC05.println("MASK OFF ");
      Serial.println("MASK OFF ");
    }
   
    if(BluetoothData=='2'){
      digitalWrite(MASK_PIN,1);
      ChannelHC05.println("MASK ON ");
      Serial.println("MASK ON ");
    }

    if(BluetoothData=='5'){
      digitalWrite(FRAME_PIN,0);
      ChannelHC05.println("FRAME OFF ");
      Serial.println("FRAME OFF ");
    }

    if(BluetoothData=='4'){
      digitalWrite(FRAME_PIN,1);
      ChannelHC05.println("FRAME ON ");
      Serial.println("FRAME ON ");
    }
  }
delay(100);// prepare for next data ...
}