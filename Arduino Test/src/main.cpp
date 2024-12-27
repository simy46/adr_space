#include <Arduino.h>
#include <EEPROM.h>

// declaration of functions
void writeStringToEEPROM(int adresse, const String &data);
String readStringFromEEPROM(int adresse);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Built in LED (L port) -> Output

  Serial.begin(9600); // init serial communication

  int adresse = 0;
  String valeurEcrite = "allo";
  for(int i = 0; i < 10; i++) {
    
  }

  writeStringToEEPROM(adresse, valeurEcrite);
  String valeurLue = readStringFromEEPROM(adresse);

  // display on serial monitor
  Serial.print("Valeur écrite : ");
  Serial.println(valeurEcrite);
  Serial.print("Valeur lue : ");
  Serial.println(valeurLue);
}

void loop() {
  // open LED
  digitalWrite(LED_BUILTIN, HIGH); // Same built in LED
  delay(10000); // Attend 10 secondes (10 000 ms)

  // close LED
  digitalWrite(LED_BUILTIN, LOW);
  delay(10000); // wait 10 sec
}

void writeStringToEEPROM(int adresse, const String &data) {
  for (unsigned int i = 0; i < data.length(); i++) {
    EEPROM.write(adresse + i, data[i]); // writing each char one at a time
  }
  EEPROM.write(adresse + data.length(), '\0'); // add null terminator
}

String readStringFromEEPROM(int adresse) {
  String result = "";
  char readChar;
  while (true) {
    readChar = EEPROM.read(adresse); // read one char at a time
    if (readChar == '\0') break; // stop if null terminator is found
    result += readChar;
    adresse++;
  }
  return result;
}