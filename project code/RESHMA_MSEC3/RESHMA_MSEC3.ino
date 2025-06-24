#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// WiFi Credentials
const char* ssid = "IOT";
const char* password = "IOT@123456789";

// ThingSpeak Credentials
unsigned long channelID = 2886635;
const char* apiKey = "TQDDK2JRTL2HTM8Y";

// Switch Pins
#define SWITCH1 16  // Switch 1 connected to D0 (GPIO16)
#define SWITCH2 5   // Switch 2 connected to D1 (GPIO5)
#define SWITCH3 4   // Switch 3 connected to D2 (GPIO4)
#define SWITCH4 0   // Switch 4 connected to D3 (GPIO0)

WiFiClient client;

void setup() {
    Serial.begin(115200);
    delay(100);

    // Connecting to WiFi
    Serial.print("Connecting to WiFi");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");

    // Initializing ThingSpeak
    ThingSpeak.begin(client);

    // Initializing Switch Pins
    pinMode(SWITCH1, INPUT);
    pinMode(SWITCH2, INPUT);
    pinMode(SWITCH3, INPUT);
    pinMode(SWITCH4, INPUT);
}

void loop() {
    // Read Switch States
    int switch1State = digitalRead(SWITCH1);
    int switch2State = digitalRead(SWITCH2);
    int switch3State = digitalRead(SWITCH3);
    int switch4State = digitalRead(SWITCH4);

    // Send data to ThingSpeak
    ThingSpeak.setField(1, switch1State);
    ThingSpeak.setField(2, switch2State);
    ThingSpeak.setField(3, switch3State);
    ThingSpeak.setField(4, switch4State);
    int response = ThingSpeak.writeFields(channelID, apiKey);
    
    // Check response from ThingSpeak
    if (response == 200) {
        Serial.println("Data sent to ThingSpeak successfully!");
    } else {
        Serial.print("Error sending data. HTTP response code: ");
        Serial.println(response);
    }

    // Wait before checking again
    delay(4000);
}
