#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFiNINA.h>

#include "arduino_secrets.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

char ssid[] = secret_ssid;
char pass[] = secret_pass;

int led = LED_BUILTIN;
int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ;
  }

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed."));
    for (;;);
  }

  display.display();
  delay(2000);

  Serial.print("Creating access point named: ");
  Serial.println(ssid);

  WiFi.beginAP(ssid, pass);

  while (WiFi.status() != WL_AP_LISTENING) {
    delay(100);
  }

  Serial.print("Address: ");
  Serial.println(WiFi.localIP());

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("AP: " + String(ssid));
  display.display();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    Serial.println("Client connected.");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Client connected.");
    display.display();

    int rssi = WiFi.RSSI();

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
      }

      if (digitalRead(led) == LOW) {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("Client connected.");
        display.println("RSSI: " + String(rssi) + " dBm");
        display.display();
        
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println();
        client.println("<html><body>");
        client.println("<h1>Arduino Server!</h1>");
        client.println("<button id='toggleButton' style='background-color:red'>Toggle LED</button>");
        client.println("<script>");
        client.println("var button = document.getElementById('toggleButton');");
        client.println("button.onclick = function() {");
        client.println("  fetch('/toggle')");
        client.println("    .then(response => response.text())");
        client.println("    .then(data => {");
        client.println("      if (data === 'on') {");
        client.println("        button.style.backgroundColor = 'green';");
        client.println("      } else {");
        client.println("        button.style.backgroundColor = 'red';");
        client.println("      }");
        client.println("    });");
        client.println("};");
        client.println("</script>");
        client.println("</body></html>");
      } else {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("Client connected.");
        display.println("RSSI: " + String(rssi) + " dBm");
        display.display();

        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println();
        client.println("<html><body>");
        client.println("<h1>Arduino Server!</h1>");
        client.println("<button id='toggleButton' style='background-color:green'>Toggle LED</button>");
        client.println("<script>");
        client.println("var button = document.getElementById('toggleButton');");
        client.println("button.onclick = function() {");
        client.println("  fetch('/toggle')");
        client.println("    .then(response => response.text())");
        client.println("    .then(data => {");
        client.println("      if (data === 'on') {");
        client.println("        button.style.backgroundColor = 'red';");
        client.println("      } else {");
        client.println("        button.style.backgroundColor = 'green';");
        client.println("      }");
        client.println("    });");
        client.println("};");
        client.println("</script>");
        client.println("</body></html>");
      }

      delay(1);
    }

    client.stop();
    Serial.println("Client disconnected.");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Client disconnected.");
    display.display();
  }
}