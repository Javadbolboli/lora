#include <Arduino.h>

#include <SPI.h>
#include <LoRa.h>


 // int buttonState=0;
//const int inpin=3;
int correctPacket=0;
int totalPacket=0;
float RS1=0;
float SN1=0;

float averageRS=0;
float averageSN=0;



void setup() {


 //pinMode(LED_BUILTIN, OUTPUT);
 // pinMode(inpin, INPUT);
  
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");

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
 char rxData[80];
byte rxIndex = 0;
char c;
  
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      char rxmesage=LoRa.read();
      Serial.print(rxmesage);
        rxData[rxIndex++]=rxmesage;
        rxData[rxIndex] = '\0';

     }

     
         if (strcmp(rxData, "hello") == 0)
    {
      correctPacket=correctPacket+1;
    }
    totalPacket=totalPacket+1;
    
    int RS=LoRa.packetRssi();
    float SN=LoRa.packetSnr();



    
    RS1=RS1+(RS*-1);
    SN1=SN1+(SN);

   averageRS =RS1/totalPacket;
   averageSN =SN1/totalPacket;


    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
    Serial.print("' with SNR ");
    Serial.println(LoRa.packetSnr());
    Serial.print("' Correct Packet ");
    Serial.println(correctPacket);
    Serial.print("' Total Packet ");
    Serial.println(totalPacket);
   // Serial.print("' Total RSSI ");
   // Serial.println(-RS1);
    Serial.print("' Average RSSI ");
    Serial.println(-averageRS);
     Serial.print("' Average SNR ");
    Serial.println(averageSN);
    
    
 
  }
}