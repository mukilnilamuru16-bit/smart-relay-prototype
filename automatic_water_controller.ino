const int lowSensor = 2;
const int highSensor = 3;
const int relayPin = 6;
const int greenLED = 7;
const int redLED = 8;
const int buzzer = 9;

void setup() {
  pinMode(lowSensor, INPUT);
  pinMode(highSensor, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(relayPin, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);
}

void loop() {

  int lowState = digitalRead(lowSensor);
  int highState = digitalRead(highSensor);

  // Tank Empty
  if (lowState == HIGH && highState == LOW) {
    digitalWrite(relayPin, HIGH);   // Pump ON
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
  }

  // Tank Full
  if (highState == HIGH) {
    digitalWrite(relayPin, LOW);    // Pump OFF
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(buzzer, LOW);
  }
}
