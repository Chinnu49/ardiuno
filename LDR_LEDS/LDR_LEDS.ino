#include <WiFiS3.h>

char ssid[] = "Telezer_J";
char pass[] = "Telezer12";

WiFiServer server(80);

int ledPin = 13;

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.println("Connecting to WiFi...");

  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    delay(2000);
  }

  Serial.println("WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    // LED ON
    if (request.indexOf("/LED=ON") != -1) {
      digitalWrite(ledPin, HIGH);
    }

    // LED OFF
    if (request.indexOf("/LED=OFF") != -1) {
      digitalWrite(ledPin, LOW);
    }

    // Web Page
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();

    client.println("<html><body>");
    client.println("<h1>Arduino UNO R4 WiFi LED Control</h1>");

    client.println("<p><a href='/LED=ON'><button>TURN ON</button></a></p>");
    client.println("<p><a href='/LED=OFF'><button>TURN OFF</button></a></p>");

    client.println("</body></html>");

    client.stop();
  }
}