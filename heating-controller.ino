#include "lib/PWMFrequency/PWMFrequency.h"

// TODO: replace with the correct pins
int inputPins[] = {A0, A1, A2, A3};
// TODO: try to avoid pins 3 and 11 as outputs because changing the PWM frequency
// changes the duration of delay()
int outputPins[] = {3, 5, 6, 9};
int inputValue = 0;

void setup()
{
  
  for (size_t i = 0; i < 4; i++)
  {
    // Set the PWM base frequency to ≈ 64 kHz / ≈ 31 kHz to avoid
    // audio interferences in audio amplifiers nearby
    setPWMPrescaler(outputPins[i], 1);

    pinMode(outputPins[i], OUTPUT);
  }
}

void loop()
{

  for (size_t i = 0; i < 4; i++)
  {
    inputValue = analogRead(inputPins[i]);
    analogWrite(outputPins[i], inputValue / 4);

    // wait for the ADC to complete
    delay(5);
  }

  delay(1000);
}
