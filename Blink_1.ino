 #define led 13
// the setup function runs once when you press reset or power the board 
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led, 1);  // change state of the LED by setting the pin to the HIGH voltage level
  delay(100);                      // wait for a second
  digitalWrite(led, 0);   // change state of the LED by setting the pin to the LOW voltage level
  delay(100);                      // wait for a second
}
