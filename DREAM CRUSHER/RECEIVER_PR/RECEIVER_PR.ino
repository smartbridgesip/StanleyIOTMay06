#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(D4,D8); // CE, CSN
const byte address[6] = "VENKY";
void setup() {
 pinMode(D1,OUTPUT);
 // digitalWtite(7,HIGH);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    if(text=="lighton"){
      digitalWrite(D1,HIGH);
   // const char text[] = "lighton";
  //radio.write(&text, sizeof(text));
   }
   else
   {
     digitalWrite(D1,LOW);
    //const char text[] = "lightoff";
  //radio.write(&text, sizeof(text));
   }
   }
    delay(1000);
  }
