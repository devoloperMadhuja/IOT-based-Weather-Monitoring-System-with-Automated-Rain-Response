#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include "index.h"
#include "DHTesp.h"
#include <Servo.h> // Servo library

#define DHTpin 14     // D5
#define LED 2         // Onboard LED
#define BUZZER 12     // D6
#define SERVOPIN 13   // D7 pin for Servo
#define ALTITUDE 1655.0

Adafruit_BMP280 bmp;
DHTesp dht;
ESP8266WebServer server(80);
Servo myservo; // Servo object

bool bmpAvailable = false;

const char* ssid = "Esha";
const char* password = "k599ckrg";

void handleRoot() {
  server.send(200, "text/html", MAIN_page);
}

void handleADC() {
  float temperatureBMP = bmpAvailable ? bmp.readTemperature() : 0.0;
  float pressure = bmpAvailable ? bmp.readPressure() / 100.0F : 0.0;

  float humidity = dht.getHumidity();
  float temperatureDHT = dht.getTemperature();

  int rainAnalog = analogRead(A0);
  int rainPercent = map(rainAnalog, 396, 169, 0, 100);
  rainPercent = constrain(rainPercent, 0, 100);

  // Optional: Smooth servo movement
  int currentAngle = myservo.read();
  if (temperatureBMP > 40 || rainPercent > 30) {
    for (int pos = currentAngle; pos <= 180; pos++) {
      myservo.write(pos);
      delay(5);
    }
    digitalWrite(BUZZER, HIGH);
  } else {
    for (int pos = currentAngle; pos >= 0; pos--) {
      myservo.write(pos);
      delay(5);
    }
    digitalWrite(BUZZER, LOW);
  }

  // Previous simple logic (now commented out)
  /*
  if (temperatureBMP > 40 || rainPercent > 30) {
    digitalWrite(BUZZER, HIGH);
    myservo.write(180);  // Move servo to full position
  } else {
    digitalWrite(BUZZER, LOW);
    myservo.write(0);    // Return to initial position
  }
  */

  String data = "{\"Rain\":\"" + String(rainPercent) +
                "\",\"Pressuremb\":\"" + String(pressure) +
                "\",\"Pressurehg\":\"" + String(pressure * 0.02953) +
                "\", \"Temperature\":\"" + String(temperatureBMP) +
                "\", \"Humidity\":\"" + String(humidity) + "\"}";

  digitalWrite(LED, !digitalRead(LED));
  server.send(200, "text/plain", data);
}

void setup() {
  Serial.begin(115200);
  dht.setup(DHTpin, DHTesp::DHT11);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  myservo.attach(SERVOPIN);
  myservo.write(0); // Initial position

  Wire.begin(D2, D1); // SDA, SCL

  if (bmp.begin(0x76) || bmp.begin(0x77)) {
    bmpAvailable = true;
    Serial.println("BMP280 sensor detected.");
  } else {
    Serial.println("BMP280 not found.");
  }

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  int retries = 0;
  while (WiFi.status() != WL_CONNECTED && retries < 20) {
    delay(500);
    Serial.print(".");
    retries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to WiFi");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFailed to connect to WiFi");
    return;
  }

  server.on("/", handleRoot);
  server.on("/readADC", handleADC);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
