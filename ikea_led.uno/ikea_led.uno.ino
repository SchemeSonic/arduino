#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX
int lightOn = 0;
char veri;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(7,OUTPUT);
}

void loop() {
  if (mySerial.available()){
    Serial.println("Serial enabled");
    Serial.println(Serial.available());
    veri=mySerial.read();
    if(!lightOn){
      digitalWrite(7,1);
      Serial.println("LED Yakildi.");
    }
    else {
      digitalWrite(7,0);
      Serial.println("LED Sonduruldu." );
    }
    lightOn = !lightOn;
  }
  delay(100);
}
