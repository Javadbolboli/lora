#include <Arduino.h>
int sensorValue_new=0;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);

}

void loop() {
int sensorValue= analogRead(A0);

  sensorValue_new = map(sensorValue, 0, 400, 0, 100);
  Serial.print("sensor Value:");
  Serial.println(sensorValue);

  Serial.print(" | ");

  Serial.print("percentage");
  Serial.print(sensorValue_new);

  Serial.println("%");
  delay(1000);
}


/*

// proměnné pro uložení výsledků
int hodnota = 0;
int procenta = 0;

  // zahájení komunikace po sériové lince
  // rychlostí 9600 baud
  Serial.begin(9600);
}

  // načtení analogové hodnoty z nastaveného pinu
  hodnota = analogRead(pinOut);
  // přepočet načtených dat, z rozsahu analogu (0-700)
  // na procenta (0-100)
  procenta = map(hodnota, 0, 700, 0, 100);
  // vytištění všech informací po sériové lince
  Serial.print("Prectena hodnota: ");
  Serial.print(hodnota);
  Serial.print(" | ");
  Serial.print(procenta);
  Serial.println("%");
  // pauza před novým měřením
  delay(500);
}
*/

