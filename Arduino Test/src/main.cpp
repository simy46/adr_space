#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Configure la LED intégrée comme sortie
}

void loop() {
  // Allumer la LED intégrée
  digitalWrite(LED_BUILTIN, HIGH);
  delay(10000); // Attend 10 secondes (10 000 ms)

  // Éteindre la LED intégrée
  digitalWrite(LED_BUILTIN, LOW);
  delay(10000); // Attend 10 secondes (10 000 ms)
}
