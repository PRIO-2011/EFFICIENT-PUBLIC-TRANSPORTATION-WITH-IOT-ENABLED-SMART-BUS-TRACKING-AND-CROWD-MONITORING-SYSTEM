#include <LiquidCrystal.h>

// Define LCD pins
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

// Define switch pins
const int RF1 = 2;
const int RF2 = 3;
const int RF3 = 4;
const int RF4 = 5;

// Define node output pins
const int NODE1 = 14;
const int NODE2 = 15;
const int NODE3 = 16;
const int NODE4 = 17;

void setup() {
    // Set switch pins as inputs
    pinMode(RF1, INPUT);
    pinMode(RF2, INPUT);
    pinMode(RF3, INPUT);
    pinMode(RF4, INPUT);
    
    // Set node pins as outputs
    pinMode(NODE1, OUTPUT);
    pinMode(NODE2, OUTPUT);
    pinMode(NODE3, OUTPUT);
    pinMode(NODE4, OUTPUT);
    
    // Initialize the LCD
    lcd.begin(16, 2);
    lcd.print("SMART BUS");
}

void loop() {
    // Read switch states
    int RF1a = digitalRead(RF1);
    int RF2a = digitalRead(RF2);
    int RF3a = digitalRead(RF3);
    int RF4a = digitalRead(RF4);

    // Control node outputs based on switch states
    digitalWrite(NODE1, RF1a);
    digitalWrite(NODE2, RF2a);
    digitalWrite(NODE3, RF3a);
    digitalWrite(NODE4, RF4a);

    // Clear LCD and display SMART BUS
    lcd.clear();
    lcd.print("SMART BUS");
    
    // Display crowd status based on switch conditions
    lcd.setCursor(0, 1);
    if (RF1a == HIGH) {
        lcd.print("Very Low     ");
        lcd.setCursor(13, 0);
        lcd.print("11 ");
    } else if (RF2a == HIGH) {
        lcd.print("Low          ");
        lcd.setCursor(13, 0);
        lcd.print("70A");
    } else if (RF3a == HIGH) {
        lcd.print("Moderate     ");
        lcd.setCursor(13, 0);
        lcd.print("41B");
    } else if (RF4a == HIGH) {
        lcd.print("High         ");
        lcd.setCursor(13, 0);
        lcd.print("7C ");
    }
    
    delay(1000);
}
