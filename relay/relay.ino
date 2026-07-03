int relayPin = 7;

void setup() {
  Serial.begin(115200);      // Start Serial Monitor
  pinMode(relayPin, OUTPUT);

  Serial.println("Relay Test Started");
}

void loop() {
  Serial.println("Relay ON");
  digitalWrite(relayPin, HIGH);
  delay(2000);

  Serial.println("Relay OFF");
  digitalWrite(relayPin, LOW);
  delay(2000);
}