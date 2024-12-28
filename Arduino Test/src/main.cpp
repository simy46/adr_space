#include <Arduino.h>

// Définir les broches
const int analogPin = A0;  // Sortie analogique
const int digitalPin = 2;  // Sortie numérique

void setup() {
  Serial.begin(9600);       // Initialiser la communication série
  pinMode(digitalPin, INPUT); // Configurer D0 comme entrée
  Serial.println("Détection sonore démarrée...");
}

void loop() {
  // Lire la valeur analogique (A0)
  int soundLevel = analogRead(analogPin);

  // Lire l'état numérique (D0)
  int thresholdState = digitalRead(digitalPin);

  // Afficher les données
  Serial.print("Niveau sonore (A0) : ");
  Serial.print(soundLevel); // Affiche la valeur brute (0-1023)

  Serial.print(" | Seuil atteint (D0) : ");
  Serial.println(thresholdState == HIGH ? "OUI" : "NON");

  delay(100); // Pause entre les lectures
}