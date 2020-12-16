#include <Arduino.h>
//#include "LowPower.h"

#define ledCount 5

int ledPin[] = {3, 4, 5, 6, 7};
int onTime = 50;
unsigned long lapse[ledCount];
unsigned long previousMillis[ledCount];
unsigned long previousLight;
int ledIndex = 0;
int primeNumber[] = {53, 71, 97, 113, 149, 167, 191, 211, 233, 257};

// the setup function runs once when you press reset or power the board
void setup()
{
  Serial.begin(9600);
  for (int ledIndex = 0; ledIndex < ledCount; ledIndex++)
  {
    pinMode(ledPin[ledIndex], OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop()
{
  int sensorValue = analogRead(A0);
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis[ledIndex] >= lapse[ledIndex])
  {
    // save the last time you blinked the LED
    previousMillis[ledIndex] = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (digitalRead(ledPin[ledIndex]) == LOW)
    {
      digitalWrite(ledPin[ledIndex], HIGH);
      lapse[ledIndex] = onTime;
    }
    else
    {
      digitalWrite(ledPin[ledIndex], LOW);
      lapse[ledIndex] = sensorValue + primeNumber[ledIndex];
    }
  }

  ledIndex = ledIndex < ledCount - 1 ? ledIndex + 1 : 0;
}