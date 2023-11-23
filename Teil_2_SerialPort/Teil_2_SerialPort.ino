/*
  Board: Arduino Uno

  https://www.arduino.cc/reference/de/
*/

// Konstanten (nicht veränderlich während Ausführung)
const int LED_PIN = 8;          // Pin 8 ~~~ 10k Widerstand ~~~ (+) LED (- großes Blech) ~~~ GND
const int TASTER_OBEN_PIN = 7;  // 5V ~~~ Taster oben ~~~ Pin 7 ~~~ 10k Widerstand ~~~ GND
const int TASTER_UNTEN_PIN = 6; // 5V ~~~ Taster unten ~~~ Pin 6 ~~~ 10k Widerstand ~~~ GND

// Variablen
// bool (false/true)
bool ledZustand;
bool tasterObenZustand;
bool tasterUntenZustand;
bool fertig = true;

// int (2-byte) = Ganzzahl mit Vorzeichen (-32.768 ... 32.767)
int zaehler = 0;

// unsigned long (4 bytes) = Ganzzahl ohne Vorzeichen (0 ... 4.294.967.295)
unsigned long startZeit = 0;
unsigned long sollDauer = 0;

String serialInput = "";

// wird einmalig beim Einschalten des Controllers ausgeführt
void setup() {
  delay(500);
  Serial.begin(115200);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("setup()");

  // Pin an dem LED angeschlossen ist, als Ausgang verwenden
  pinMode(LED_PIN, OUTPUT);

  // Pins von Tastern als Eingänge
  pinMode(TASTER_OBEN_PIN, INPUT);
  pinMode(TASTER_UNTEN_PIN, INPUT);
}

// wird ständig von Controller nach setup() ausgeführt
void loop() {

  // Digital Eingang von Taster lesen und Zustand in Variable schreiben
  tasterObenZustand = digitalRead(TASTER_OBEN_PIN);
  // Zustand von unterem Taster in Variable schreiben
  tasterUntenZustand = digitalRead(TASTER_UNTEN_PIN);
  ledZustand = digitalRead(LED_PIN);

  /*
    // Übung 1 - Welcher Taster wurde gedrückt?

    if (tasterObenZustand == true) {

      Serial.println("Taster oben");
      delay(500);
    }

    if (tasterUntenZustand == true) {

      Serial.println("Taster unten");
      delay(500);
    }
  */

  /*
    // Übung 2 - Zähler

    // zaehler Variable bei jedem Tastendruck inkrementieren
    if (tasterObenZustand == true) {

      zaehler++;
      Serial.println(zaehler);

      delay(500);
    }

    // zaehler Variable zurücksetzen
    if (tasterUntenZustand == true) {

      zaehler = 0;
      Serial.println(zaehler);

      delay(500);
    }
  */

  /*
    // Übung 3 - Eieruhr
    if (tasterObenZustand == true) {

      Serial.println("start");
      // Zeitpunkt in Variable schreiben
      startZeit = millis();
      digitalWrite(LED_PIN, true);
      fertig = false;
    }

    if (fertig == false) {
      // ist aktuelle Zeit größergleich gespeicherter Zeitpunkt + 5s?
      if (millis() >= startZeit + 5000) {

        Serial.println("fertig");
        digitalWrite(LED_PIN, false);
        fertig = true;

      } else {
        // Restzeit schreiben
        Serial.println(5000 - (millis() - startZeit));
      }

      delay(1000);
    }
  */

  /*
    // Übung 4 - Echo

    while (Serial.available() > 0) {

      int b = Serial.read();

      // Ende der Zeile?
      if (b == '\n') {

        Serial.println(serialInput);
        serialInput = "";
      } else {

        serialInput += char(b);
      }
    }
  */

  /*
    // Übung 5 - Einstellbare Eieruhr

    while (Serial.available() > 0) {

      int b = Serial.read();
      char c = char(b);

      switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          // nur Zahlen erlauben
          serialInput += c;
          break;
      }

      // Ende der Zeile?
      if (b == '\n') {

        sollDauer = atol(serialInput.c_str());
        Serial.print("Dauer eingestellt auf ");
        Serial.print(sollDauer);
        Serial.println("ms");

        serialInput = "";
      }
    }


    if (tasterObenZustand == true) {

      Serial.println("start");
      // Zeitpunkt in Variable schreiben
      startZeit = millis();
      digitalWrite(LED_PIN, true);
      fertig = false;
    }

    if (fertig == false) {
      // ist aktuelle Zeit größergleich gespeicherter Zeitpunkt + sollDauer?
      if (millis() >= startZeit + sollDauer) {

        Serial.println("fertig");
        digitalWrite(LED_PIN, false);
        fertig = true;

      } else {
        // Restzeit schreiben
        Serial.println(sollDauer - (millis() - startZeit));
      }

      delay(100);
    }
  */

}
