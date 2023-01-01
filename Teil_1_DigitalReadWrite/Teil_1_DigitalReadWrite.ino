/*
  Board: Arduino Uno

  https://www.arduino.cc/reference/de/
*/

// Konstanten (nicht veränderlich während Ausführung)
const int ledPin =  8;        // Pin 8 ~~~ 10k Widerstand ~~~ (+) LED (- großes Blech) ~~~ GND
const int tasterObenPin = 7;  // 5V ~~~ Taster oben ~~~ Pin 7 ~~~ 10k Widerstand ~~~ GND
const int tasterUntenPin = 6; // 5V ~~~ Taster unten ~~~ Pin 6 ~~~ 10k Widerstand ~~~ GND

// Variablen
// bool (false/true)
bool ledZustand;
bool tasterObenZustand;
bool tasterUntenZustand;

// int (2-byte) = Ganzzahl mit Vorzeichen (-32.768 ... 32.767)
int zaehler = 0;

// unsigned long (4 bytes) = Ganzzahl ohne Vorzeichen (0 ... 4.294.967.295)
unsigned long startZeit = 0;
unsigned long endZeit = 0;

// wird einmalig beim Einschalten des Controllers ausgeführt
void setup() {

  // Pin an dem LED angeschlossen ist, als Ausgang verwenden
  pinMode(ledPin, OUTPUT);

  // Pins von Tastern als Eingänge
  pinMode(tasterObenPin, INPUT);
  pinMode(tasterUntenPin, INPUT);
}

// wird ständig von Controller nach setup() ausgeführt
void loop() {

  // Digital Eingang von Taster lesen und Zustand in Variable schreiben
  tasterObenZustand = digitalRead(tasterObenPin);

  // Inbetriebnahme EAs

  /*
    // Übung 1 - digitalWrite()
    // LED an/aus schalten, je nach Zustand von Taster

    digitalWrite(ledPin, tasterObenZustand == true);
  */

  // Zustand von unterem Taster in Variable schreiben
  tasterUntenZustand = digitalRead(tasterUntenPin);

  /*
    // Übung 2 - ODER

    digitalWrite(ledPin, tasterObenZustand == true || tasterUntenZustand == true);
  */

  // Anpassen an Kundenwünsche

  /*
    // Übung 3 - UND

    digitalWrite(ledPin, tasterObenZustand == true && tasterUntenZustand == true);
  */

  /*
    // Übung 4 - Licht AN/AUS
    // Taster oben:   LED an
    // Taster unten:  LED aus

    if (tasterObenZustand == true) {

      digitalWrite(ledPin, true);
    }

    if (tasterUntenZustand == true) {

      digitalWrite(ledPin, false);
    }
  */

  ledZustand = digitalRead(ledPin);

  /*
    // Übung 5 - umschalten
    // LED mit einem Taster umschalten (toggeln)

    if (tasterObenZustand == true) {

      digitalWrite(ledPin, !ledZustand);
      delay(500);
    }
  */

  /*
    // Übung 6 - umschalten (doppelter Code)
    // LED mit beiden Tastern umschalten (toggeln)

    if (tasterObenZustand == true) {

      digitalWrite(ledPin, !ledZustand);
      delay(500);
    }

    if (tasterUntenZustand == true) {

      digitalWrite(ledPin, !ledZustand);
      delay(500);
    }
  */

  /*
    // Übung 7 - umschalten (ODER)
    // LED mit beiden Tastern umschalten (toggeln)

    if (tasterObenZustand == true || tasterUntenZustand == true) {

      digitalWrite(ledPin, !ledZustand);
      delay(500);
    }
  */

  /*
    // Übung 8 - Zähler

    // zaehler Variable bei jedem Tastendruck inkrementieren
    if (tasterObenZustand == true) {

      zaehler++;

      if (zaehler >= 3) {
        digitalWrite(ledPin, true);
      }

      delay(500);
    }

    // zaehler Variable zurücksetzen
    if (tasterUntenZustand == true) {

      zaehler = 0;
      digitalWrite(ledPin, false);
    }
  */

  /*
    // Übung 9 - Eieruhr
    if (tasterObenZustand == true) {
      // Zeitpunkt in Variable schreiben
      startZeit = millis();
      digitalWrite(ledPin, true);
    }

    // ist aktuelle Zeit größergleich gespeicherter Zeitpunkt + 5s?
    if (millis() >= startZeit + 5000) {

      digitalWrite(ledPin, false);
    }
  */

  /*
    // Übung 10 - Blinklicht

    // Zeit abelaufen?
    if (millis() >= startZeit + 1000) {

      digitalWrite(ledPin, !ledZustand);

      startZeit = millis();
    }
  */

  /*
    // Übung 11 - Blitzlicht
    // LED an 50ms
    // LED aus 1s

    if ((ledZustand == true && millis() >= startZeit + 50) ||
        (ledZustand == false && millis() >= startZeit + 1000)) {

      digitalWrite(ledPin, !ledZustand);

      startZeit = millis();
    }
  */

  /*
    // Übung 12 - Zeit messen

    // Zeitpunkt wann Taster gedrückt wurde, in Variable schreiben
    if (tasterObenZustand == true && startZeit == 0) {

      startZeit = millis();
    }

    // Zeitpunkt wann Taster losgelassen wurde, mit startZeit verrechnen und in Variable schreiben
    if (tasterObenZustand == false && startZeit > 0) {

      endZeit = millis() + (millis() - startZeit);
      startZeit = 0;
    }

    // LED ansteuern
    if (endZeit > 0) {

      digitalWrite(ledPin, true);

      if (millis() >= endZeit) {

        digitalWrite(ledPin, false);

        endZeit = 0;
      }
    }
  */

  /*
    // Übung 13 - for Schleife
    // 3 mal blinken, 2s Pause

    for (int i = 0; i < 3; i++) {

      digitalWrite(ledPin, true);

      delay(200);

      digitalWrite(ledPin, false);

      delay(500);
    }

    delay(1500);
  */

  /*
    // Übung 14 - while Schleife
    // 2 mal blinken, 2s Pause

    zaehler = 0;

    while (zaehler < 2) {

      digitalWrite(ledPin, true);

      delay(200);

      digitalWrite(ledPin, false);

      delay(500);

      zaehler++;
    }

    delay(1500);
  */

  /*
    // Übung 15 - do while Schleife
    // 1 mal blinken, 2s Pause

    do {

      digitalWrite(ledPin, true);

      delay(200);

      digitalWrite(ledPin, false);

      delay(500);

      zaehler++;

    } while (zaehler < 2);

    delay(1500);
  */

}
