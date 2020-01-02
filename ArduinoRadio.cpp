// Basic Bluetooth sketch HC-05_02
// Connect the HC-05 module and communicate using the serial monitor
//
// The HC-05 defaults to commincation mode when first powered on.
// The default baud rate for communication mode is 9600
//

#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 RX.
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.

// Based on http://www.martyncurrey.com/arduino-with-hc-05-bluetooth-module-in-slave-mode/

char c = ' ';
String s;

const int vcc = 7;
const int CS = 11;
const int INC = 10;
const int UD = 9;

void setup()
{
    Serial.begin(9600);
    Serial.println("Arduino is ready");

    pinMode(LED_BUILTIN, OUTPUT);

    // HC-05 default serial speed for commincation mode is 9600
    BTserial.begin(9600);

    pinMode(vcc, OUTPUT);
    pinMode(CS, OUTPUT);
    pinMode(INC, OUTPUT);
    pinMode(UD, OUTPUT);
    digitalWrite(CS, HIGH);
    digitalWrite(INC, HIGH);
    digitalWrite(UD, HIGH);
}

void loop()
{
    // Keep reading from HC-05 and send to Arduino Serial Monitor
    if (BTserial.available()) {
        c = BTserial.read();

        if (c == '\r' || c == '\n') {
            s = "";
        }
        else {
            s = s + c;

    Serial.println(s);
            if (s == "VolUp") {
                setResistance(1);
                digitalWrite(vcc, HIGH);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(100);
                digitalWrite(LED_BUILTIN, LOW);
                
            }
            else if (s == "VolDown") {
                setResistance(2);
                digitalWrite(vcc, HIGH);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(100);
                digitalWrite(LED_BUILTIN, LOW);
                
            }
            else if (s == "Skip") {
                setResistance(3);
                digitalWrite(vcc, HIGH);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(100);
                digitalWrite(LED_BUILTIN, LOW);
                
            }
            else if (s == "Prev") {
                setResistance(4);
                digitalWrite(vcc, HIGH);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(100);
                digitalWrite(LED_BUILTIN, LOW);
                
            }
            else if (s == "Pause") {
                setResistance(7);
                digitalWrite(vcc, HIGH);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(100);
                digitalWrite(LED_BUILTIN, LOW);
                
            }
            else if (s == "Mute") {
                setResistance(15);
                digitalWrite(vcc, HIGH);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(100);
                digitalWrite(LED_BUILTIN, LOW);
                
            }
            else if (s == "Mode") {
                setResistance(10);
                digitalWrite(vcc, HIGH);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(100);
                digitalWrite(LED_BUILTIN, LOW);
                
            }
            else if (s == "Repeat") {
                setResistance(6);
                digitalWrite(vcc, HIGH);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(100);
                digitalWrite(LED_BUILTIN, LOW);
                
            }
        }
    }
    
    digitalWrite(vcc, LOW);
    // Keep reading from Arduino Serial Monitor and send to HC-05
    if (Serial.available()) {
        c = Serial.read();
        BTserial.write(c);
    }
}

void setResistance(int percent)
{
    digitalWrite(UD, LOW);
    digitalWrite(CS, LOW);
    for (int i = 0; i < 100; i++) {
        digitalWrite(INC, LOW);
        delayMicroseconds(1);
        digitalWrite(INC, HIGH);
        delayMicroseconds(1);
    }

    digitalWrite(UD, HIGH);
    for (int i = 0; i < percent; i++) {
        digitalWrite(INC, LOW);
        delayMicroseconds(1);
        digitalWrite(INC, HIGH);
        delayMicroseconds(1);
    }

    digitalWrite(CS, HIGH);
}
