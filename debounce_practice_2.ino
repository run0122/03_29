const int inputPin = 2;
const int ledPin = 13;
const int debounceDelay = 100;

boolean debounce(int pin) {
  boolean state;
  boolean previousState;

  previousState = digitalRead(pin);
  for (int counter = 0; counter < debounceDelay; counter++) {
    delay(1);
    state = digitalRead(pin);
    if (state != previousState) {
      counter = 0;
      previousState = state;
    }
  }
  if(state==LOW)
    return true;
  else
    return false;
}

int count;

void setup() {
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (debounce(inputPin)) {
    digitalWrite(ledPin, HIGH);
    count++;
    Serial.println(count);
  }
}
