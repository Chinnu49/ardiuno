/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/AnalogReadSerial/
*/

// the setup routine runs once when you press reset:
// Joystick Pins
// Arduino UNO R4 WiFi + Joystick + 4 LEDs

// Arduino UNO R4 WiFi + Joystick + 4 LEDs

const int VRX = A0;
const int VRY = A1;
const int SW  = 2;

const int LED_LEFT  = 4;
const int LED_RIGHT = 5;
const int LED_UP    = 6;
const int LED_DOWN  = 7;

int xValue = 0;
int yValue = 0;
int buttonState = 0;

void setup() {
  Serial.begin(9600);

  pinMode(SW, INPUT_PULLUP);

  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
  pinMode(LED_UP, OUTPUT);
  pinMode(LED_DOWN, OUTPUT);

  digitalWrite(LED_LEFT, LOW);
  digitalWrite(LED_RIGHT, LOW);
  digitalWrite(LED_UP, LOW);
  digitalWrite(LED_DOWN, LOW);

  Serial.println("Arduino UNO R4 WiFi - Joystick Test");
}

void loop() {

  xValue = analogRead(VRX);
  yValue = analogRead(VRY);
  buttonState = digitalRead(SW);

  // Turn OFF all LEDs first
  digitalWrite(LED_LEFT, LOW);
  digitalWrite(LED_RIGHT, LOW);
  digitalWrite(LED_UP, LOW);
  digitalWrite(LED_DOWN, LOW);

  String direction = "CENTER";

  // Detect direction
  if (xValue < 300) {
    direction = "LEFT";
    digitalWrite(LED_LEFT, HIGH);
  }
  else if (xValue > 700) {
    direction = "RIGHT";
    digitalWrite(LED_RIGHT, HIGH);
  }
  else if (yValue < 300) {
    direction = "DOWN";
    digitalWrite(LED_DOWN, HIGH);
  }
  else if (yValue > 700) {
    direction = "UP";
    digitalWrite(LED_UP, HIGH);
  }

  Serial.print("X = ");
  Serial.print(xValue);

  Serial.print("   Y = ");
  Serial.print(yValue);

  Serial.print("   Direction = ");
  Serial.print(direction);

  Serial.print("   Button = ");

  if (buttonState == LOW)
    Serial.println("Pressed");
  else
    Serial.println("Released");

  delay(100);
}