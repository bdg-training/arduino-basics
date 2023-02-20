/*
  Board: Arduino Uno

  https://www.arduino.cc/reference/de/
*/

// Konstanten (nicht veränderlich während Ausführung)
const int LED_PIN = 9;  // Pin 9 ~~~ 10k Widerstand ~~~ (+) LED (- großes Blech) ~~~ GND
// LDR = Light dependent resistor
const int LDR_PIN = A0; // 5V ~~~ LDR ~~~ Pin A0 ~~~ 1k Widerstand ~~~ GND

// Variablen
// int (2-byte) = Ganzzahl mit Vorzeichen (-32.768 ... 32.767)
int ldrWert = 0;

// wird einmalig beim Einschalten des Controllers ausgeführt
void setup() {
  delay(500);
  Serial.begin(115200);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("setup()");

  // Pin an dem LED angeschlossen ist, als Ausgang verwenden
  pinMode(LED_PIN, OUTPUT);
}

// wird ständig von Controller nach setup() ausgeführt
void loop() {

  /*
    // Übung 1 - Analogwert schreiben (Fading)

    // Schleife von 0 bis 255
    for (int i = 0 ; i <= 255; i += 5) {
      // Analogausgang schreiben (Werte von 0..255)
      analogWrite(LED_PIN, i);

      delay(30);
    }

    // Schleife von 255 bis 0
    for (int i = 255 ; i >= 0; i -= 5) {

      analogWrite(LED_PIN, i);

      delay(30);
    }
  */

  /*
    // Übung 2 - Analogwert lesen

    // Werte von 0..1023 möglich (10 Bit Auflösung)
    //    0 = 0V
    // 1023 = 5V
    ldrWert = analogRead(LDR_PIN);

    Serial.println(ldrWert);

    delay(500);
  */

  /*
    // Übung 3 - Dämmerungsschalter (Digital)

    ldrWert = analogRead(LDR_PIN);

    if (ldrWert < 200) {

      digitalWrite(LED_PIN, true);
    } else {
      digitalWrite(LED_PIN, false);
    }

    Serial.println(ldrWert);

    delay(200);
  */

  /*
    // Übung 4 - Dämmerungsschalter (Analog)

    ldrWert = analogRead(LDR_PIN);
    // map() skaliert Werte von 0..1023 zu 255..0
    // je heller die Umgebung (höhere Spannung am A0),
    // desto dunkler wird die LED
    // Beispiele:
    // 0 -> 255
    // 511 -> 128
    // 1023 -> 0
    // LDR mit Finger abdunkeln, Messwert bei x eintragen -> map(ldrWert, x, 1023, 255, 0)
    // LDR Umgebungslicht messen lassen, Messwert bei y eintragen -> map(ldrWert, 35, y, 255, 0)
    analogWrite(LED_PIN, map(ldrWert, 0, 1023, 255, 0));

    Serial.println(ldrWert);

    delay(200);
  */

}
