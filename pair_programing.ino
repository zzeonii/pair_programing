const int LED = 6;
const int BUTTON = 2;
int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {
  //blink();
  button();
  Serial.println(buttonPushCounter);
  if ((buttonPushCounter % 2) == 1)
    blink();
  if ((buttonPushCounter % 2) == 0)
    no_blink();
}

void blink() {
  digitalWrite(LED, HIGH);
}

void no_blink() {
  digitalWrite(LED, LOW);
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