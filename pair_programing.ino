const int LED = 6;
const int BUTTON = 2;

int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;

int ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  button();
  if ((buttonPushCounter%2)==1)
    blink();
  else{
    digitalWrite(LED, LOW);
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

