#include <Arduino.h>

const int sensorPin = A0;  // Broche connectée à la sortie analogique du capteur
int lastValue = -1;        // Dernière valeur lue (initialisée à une valeur impossible)

void setup() {
  Serial.begin(9600);      // Initialise la communication série
  Serial.println("Démarrage du capteur d'humidité du sol...");
}

void loop() {
  int currentValue = analogRead(sensorPin); // Lire la valeur analogique du capteur (0 à 1023)

  // Vérifier si la valeur a changé
  if (currentValue != lastValue) {
    lastValue = currentValue; // Mettre à jour la dernière valeur
    Serial.print("Humidité du sol : ");
    Serial.println(currentValue); // Afficher la nouvelle valeur dans le moniteur série
  }

  delay(500); // Petite pause pour éviter un trop grand nombre de lectures
}
