
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

#define REPORTING_PERIOD_MS     1000

PulseOximeter pox;

int tsLastReport = 0;

void onBeatDetected()
{
    Serial.println(" ");
}

void setup()
{
    Serial.begin(9600);

    pox.begin();

}

void loop()
{

    pox.update();

    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {

        Serial.print(pox.getSpO2());
        Serial.print("\n");

        tsLastReport = millis();
    }
}
