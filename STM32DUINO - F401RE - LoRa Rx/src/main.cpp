#include <Arduino.h>

#include <SPI.h>
#include <LoRa.h>

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

  LoRa.setTxPower(20);


  LoRa.setSpreadingFactor(7); 
LoRa.setSignalBandwidth(125E3); 
LoRa.setCodingRate4(8);

Serial.println("setup complete");
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello");
  LoRa.endPacket();

  counter++;

  delay(500);
}