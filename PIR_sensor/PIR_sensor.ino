const int pirPin = 2;
const int ledPin = 13;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  Serial.println("PIR Sensor Initializing...");
  delay(30000); // Allow sensor to stabilize
  Serial.println("Ready!");
}

void loop() {
  int motion = digitalRead(pirPin);

  if (motion == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion Detected!");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("No Motion");
  }

  delay(10);
}