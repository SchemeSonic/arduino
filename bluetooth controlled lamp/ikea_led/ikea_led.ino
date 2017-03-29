#include <SoftwareSerial.h>

SoftwareSerial mySerial(3,4); // RX, TX

byte receivedData;
int  LED = 13;

void setup()
{
  pinMode(LED, OUTPUT);
  mySerial.begin(38400);
  Serial.begin(9600);
}

void loop() 
{    
  while (!mySerial.available());      // If serial not available, wait.
  
  receivedData = mySerial.read();     // Store received data
  Serial.println(receivedval);        // Print received data in Serial Monitor
  
  if (receivedData == 176)            // If input is `1` 
    digitalWrite(LED, HIGH);

  if (receivedData == 177)            // If input is `2`
    digitalWrite(LED, LOW);

  if (receivedData == 178) {          // If input is `3`
    
    for (int i = 0; i < 30; i++) {
      
      digitalWrite(LED, HIGH);
      delay(20);
      digitalWrite(LED, LOW);
      delay(20);
      
     }
     
  }
  
 }



