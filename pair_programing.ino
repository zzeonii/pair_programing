#include "pitches.h"

const int LED = 6;
const int BUTTON = 2;
const int BUZZER = 11;

bool trigger = true;

int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;

int ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  button();
  if ((buttonPushCounter % 2) == 1)
    buzzer();
  else {
    trigger = true;
  }

  if ((millis() % 500) == 0) {
    Serial.println(buttonPushCounter);
  }
}

void button() {
  buttonState = digitalRead(BUTTON);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
    }
  }

  lastButtonState = buttonState;
}

void blink() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(LED, ledState);
  }
  // if ((millis() % 200) == 0) {
  //   Serial.println((String) "currentMillis" + currentMillis);
  //   Serial.println((String) "previousMillis" + previousMillis);
  // }
}

void buzzer() {
  int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
  };

  int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4
  };

  if (trigger == true) {
    for (int thisNote = 0; thisNote < 8; thisNote++) {

      int noteDuration = 1000 / noteDurations[thisNote];
      tone(BUZZER, melody[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      noTone(BUZZER);
      if (thisNote == 7){
        trigger = false;
        break;
      }
    }
  }
}
