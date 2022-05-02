#include <Arduino.h>

#include <SPI.h>
#include <LoRa.h>

int counter = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(169E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setTxPower(27);
  LoRa.setSpreadingFactor(7); 
  LoRa.setSignalBandwidth(125E3); 
  LoRa.setCodingRate4(8);
}

void loop() {
  String message= "hello";
  Serial.print("Sending packet: ");
  Serial.println(counter);
  Serial.println("message: ");
  Serial.println(message);

  // send packet
  
  LoRa.beginPacket();
  LoRa.print(message);
 // LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(2000); 
}