
const int LED_REIHE_1 =  12;
const int LED_REIHE_2 =  11;
const int LED_REIHE_3 =  10;
const int LED_REIHE_4 =  9;

const int LED_SPALTE_1 =  7;
const int LED_SPALTE_2 =  6;
const int LED_SPALTE_3 =  5;

const unsigned int delayAn = 500;

int schritt;
int i;
bool heller;

unsigned long startZeit = 0;
unsigned long dauer = 0;

// wird einmalig beim Einschalten des Controllers ausgeführt
void setup() {
  pinMode(LED_REIHE_1, OUTPUT);
  pinMode(LED_REIHE_2, OUTPUT);
  pinMode(LED_REIHE_3, OUTPUT);
  pinMode(LED_REIHE_4, OUTPUT);

  pinMode(LED_SPALTE_1, OUTPUT);
  pinMode(LED_SPALTE_2, OUTPUT);
  pinMode(LED_SPALTE_3, OUTPUT);

  reset();

  startZeit = millis();

  while (millis() < startZeit + 2000) {
    // LED Test
    alleAn();
  }
}

// wird ständig von Controller nach setup() ausgeführt
void loop() {

  switch (schritt) {
    case 0:
    default:
      // Dauer in Millisekunden, wie lange Folgeschritt ausgeführt werden soll
      warte(1000);
      break;

    case 1:
      led1x1();
      break;

    case 2:
      warte(1000);
      break;

    case 3:
      led1x1();
      led1x2();
      break;

    case 4:
      warte(1000);
      break;

    case 5:
      led1x1();
      led1x2();
      led2x1();
      break;

    case 6:
      warte(1000);
      break;

    case 7:
      led1x1();
      led1x2();
      led2x1();
      led2x2();
      break;

    case 8:
      warte(1000);
      break;

    case 9:
      reset();
      break;

    // ...

    case 10:
      warte(0);
      schritt = 0;
      break;
  }

  // wenn dauer gesetzt ist, dann nach n Millisekunden, Schritt inkrementieren
  if (dauer > 0) {
    if (millis() > startZeit + dauer) {
      schritt++;
      dauer = 0;
    }
  }


  /*reset();

  if (heller) {
    i += 1;
  } else {
    i -= 1;
  }

  if (i < 0) {
    i = 0;
    heller = true;
    schritt++;
  }

  if (i > 25) {
    i = 25;
    heller = false;
  }

  delay(i);*/
}

void warte(unsigned long d) {

  startZeit = millis();
  dauer = d;
  schritt++;
  reset();
}

void alleAn() {
  led1x1();
  led2x1();
  led3x1();
  led4x1();
  led1x2();
  led2x2();
  led3x2();
  led4x2();
}

// LED Reihe 1 / Spalte 1
void led1x1() {

  reset();
  digitalWrite(LED_REIHE_1, HIGH);
  digitalWrite(LED_SPALTE_1, LOW);
  delayMicroseconds(delayAn);
}

// LED Reihe 2 / Spalte 1
void led2x1() {

  reset();
  digitalWrite(LED_REIHE_2, HIGH);
  digitalWrite(LED_SPALTE_1, LOW);
  delayMicroseconds(delayAn);
}

// LED Reihe 3 / Spalte 1
void led3x1() {

  reset();
  digitalWrite(LED_REIHE_3, HIGH);
  digitalWrite(LED_SPALTE_1, LOW);
  delayMicroseconds(delayAn);
}

// LED Reihe 4 / Spalte 1
void led4x1() {

  reset();
  digitalWrite(LED_REIHE_4, HIGH);
  digitalWrite(LED_SPALTE_1, LOW);
  delayMicroseconds(delayAn);
}

// LED Reihe 1 / Spalte 2
void led1x2() {

  reset();
  digitalWrite(LED_REIHE_1, HIGH);
  digitalWrite(LED_SPALTE_2, LOW);
  delayMicroseconds(delayAn);
}

// LED Reihe 2 / Spalte 2
void led2x2() {

  reset();
  digitalWrite(LED_REIHE_2, HIGH);
  digitalWrite(LED_SPALTE_2, LOW);
  delayMicroseconds(delayAn);
}

// LED Reihe 3 / Spalte 2
void led3x2() {

  reset();
  digitalWrite(LED_REIHE_3, HIGH);
  digitalWrite(LED_SPALTE_2, LOW);
  delayMicroseconds(delayAn);
}

// LED Reihe 4 / Spalte 2
void led4x2() {

  reset();
  digitalWrite(LED_REIHE_4, HIGH);
  digitalWrite(LED_SPALTE_2, LOW);
  delayMicroseconds(delayAn);
}

void reset() {

  digitalWrite(LED_REIHE_1, LOW);
  digitalWrite(LED_REIHE_2, LOW);
  digitalWrite(LED_REIHE_3, LOW);
  digitalWrite(LED_REIHE_4, LOW);

  digitalWrite(LED_SPALTE_1, HIGH);
  digitalWrite(LED_SPALTE_2, HIGH);
  digitalWrite(LED_SPALTE_3, HIGH);
}
