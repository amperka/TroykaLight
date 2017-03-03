/****************************************************************************/
//  Function:       Cpp file for TroykaLight
//  Hardware:       GL5528
//  Arduino IDE:    Arduino-1.6.11
//  Author:         Igor Dementiev
//  Date:           Feb 28,2017
//  Version:        v1.0
//  by www.amperka.ru
/****************************************************************************/

#include "TroykaLight.h"

#define R_DIVIDER       10
#define LDR_10LUX       14
#define LDR_GAMMA       0.6
#define SAMPLE_TIMES    32

LIGHT::LIGHT(uint8_t pin) {
    _pin = pin;
}

float LIGHT::readLight() {
    int sensorValue = 0;
    float sensorLight = 0;
    float sensorResistance = 0;
    for (int i = 0; i < SAMPLE_TIMES; i++) {
        sensorValue += analogRead(_pin);
    }
    sensorValue = sensorValue >> 5;
    sensorResistance = R_DIVIDER / (1023.0 / sensorValue - 1.0);
    sensorLight = 10.0 * pow(LDR_10LUX / sensorResistance, 1.0 / LDR_GAMMA);
    return sensorLight;
}
