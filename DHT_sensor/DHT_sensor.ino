#include "DHT.h"

#define DHTPIN 2        // DATA pin connected to D2
#define DHTTYPE DHT11   // Change to DHT22 if using that sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT Sensor Test");
  dht.begin();
}

void loop() {
  delay(2000); // sensor needs delay

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %  |  Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}
