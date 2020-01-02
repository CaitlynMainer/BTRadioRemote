#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3);

int analogPin = 0;
int raw = 0;
int Vin = 5;
float Vout = 0;
float R1 = 2200;
float R2 = 0;
float buffer = 0;

void setup()
{
  Serial.begin(9600);
  BTserial.begin(9600);
}

void loop()
{
  raw = analogRead(analogPin);
  if (raw)
  {
    buffer = raw * Vin;
    Vout = (buffer) / 1024.0;
    buffer = (Vin / Vout) - 1;
    R2 = R1 * buffer;
    Serial.print("R2: ");
    Serial.println(R2);
    if (1300 <= R2 && R2 <= 1450) {
      Serial.println("VolUp");
      char test[] = "VolUp";
      BTserial.print(test);
      BTserial.write('\r');
    } else if (1600 <= R2 && R2 <= 1850) {
      Serial.println("VolDown ");
      char test[] = "VolDown";
      BTserial.print(test);
      BTserial.write('\r');
    } else if (3100 <= R2 && R2 <= 3400) {
      Serial.println("Skip");
      char test[] = "Skip";
      BTserial.print(test);
      BTserial.write('\r');
    } else if (4300 <= R2 && R2 <= 4600) {
      Serial.println("Prev");
      char test[] = "Prev";
      BTserial.print(test);
      BTserial.write('\r');
    } else if (1900 <= R2 && R2 <= 2100) {
      Serial.println("Play/Pause");
      char test[] = "Pause";
      BTserial.print(test);
      BTserial.write('\r');
    } else if (2400 <= R2 && R2 <= 2700) {
      Serial.println("Mute");
      char test[] = "Mute";
      BTserial.print(test);
      BTserial.write('\r');
    } else if (6700 <= R2 && R2 <= 8900) {
      Serial.println("Mode");
      char test[] = "Mode";
      BTserial.print(test);
      BTserial.write('\r');
    } else if (13000 <= R2 && R2 <= 16000) {
      Serial.println("Repeat");
      char test[] = "Repeat";
      BTserial.print(test);
      BTserial.write('\r');
    }
    delay(250);
  }
}
