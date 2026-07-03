#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int irPin = 2;
const int trigPin = 9;
const int echoPin = 10;

bool lastIRState = HIGH;
float detectDistance = 0;

float readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0)
    return 0;

  return duration * 0.0343 / 2;
}

void setup() {
  pinMode(irPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
}

void loop() {

  bool irState = digitalRead(irPin);
  float distance = readDistance();

  // Detect transition: no object -> object detected
  if (lastIRState == HIGH && irState == LOW) {
    detectDistance = distance;

    Serial.print("IR triggered at: ");
    Serial.print(detectDistance);
    Serial.println(" cm");
  }

  lastIRState = irState;

  lcd.setCursor(0, 0);

  if (irState == LOW) {
    lcd.print("IR Detect Dist ");
    lcd.setCursor(0, 1);
    lcd.print(detectDistance, 1);
    lcd.print(" cm        ");
  } else {
    lcd.print("Current Dist  ");
    lcd.setCursor(0, 1);
    lcd.print(distance, 1);
    lcd.print(" cm        ");
  }

  delay(100);
}