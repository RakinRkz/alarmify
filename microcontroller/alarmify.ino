#include <ESP8266WiFi.h>
#include <ESP8266NTPClient.h>
#include <WiFiUdp.h>

// Network credentials
const char* ssid = "your_SSID"; // Replace with your network SSID
const char* password = "your_PASSWORD"; // Replace with your network password

// NTP Server pool
static const uint32_t ntpServerPool[] = { 
  199.107.133.61   // Example NTP server, replace with your preferred NTP server
};

// UDP instance needed to send and receive packets over UDP
WiFiUDP udp;

// Time variables
unsigned long localEpoch;
int daylightOffset = 8 * 3600; // Adjust this value according to your timezone

// Initialize NTP Client
ESP8266NTPClient ntpClient(udp, ntpServerPool, daylightOffset);

// LED pin definition
#define LED_PIN 2

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status()!= WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");

  // Initialize NTP client
  ntpClient.begin();
  ntpClient.update();

  // Print the time obtained from the NTP server
  Serial.print("Local time: ");
  Serial.println(ntpClient.getFormattedTime());

  // Configure LED pin as output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Update the time every second
  ntpClient.update();

  // Check if it's time for the alarm
  if (isTimeForAlarm(7, 30)) { // Example: Alarm set for 7:30 AM
    digitalWrite(LED_PIN, HIGH); // Trigger the LED
    delay(10000); // Keep the LED on for 10 seconds
    digitalWrite(LED_PIN, LOW); // Turn the LED off
  }
}

bool isTimeForAlarm(int hour, int minute) {
  // Get current time
  int currentHour = ntpClient.getHours();
  int currentMinute = ntpClient.getMinutes();
  
  return (currentHour == hour && currentMinute == minute);
}
