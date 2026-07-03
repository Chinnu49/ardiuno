const int flamePin = 2;
const int ledPin = 13;   // Built-in LED

int flameState = 0;

void setup() {
  Serial.begin(9600);

  pinMode(flamePin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.println("Flame Sensor Test Started");
}

void loop() {
  flameState = digitalRead(flamePin);

  if (flameState == LOW) {
    // Most flame sensors give LOW when fire is detected
    Serial.println("🔥 Flame Detected!");
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println("No Flame");
    digitalWrite(ledPin, LOW);
  }

  delay(300);
}