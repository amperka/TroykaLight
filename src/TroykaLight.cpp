/****************************************************************************/
//  Function:       Cpp file for TroykaLight
//  Hardware:       GL5528
//  Arduino IDE:    Arduino-1.8.3
//  Author:         Igor Dementiev
//  Date:           Apr 19,2018
//  Version:        v1.0.0
//  by www.amperka.ru
/****************************************************************************/

#include "TroykaLight.h"

TroykaLight::TroykaLight(uint8_t pin) {
    _pin = pin;
}

void TroykaLight::read() {
    int sensorADC = 0;
    float sensorRatio = 0;
    float sensorResistance = 0;
    for (int i = 0; i < SAMPLE_TIMES; i++) {
        sensorADC += analogRead(_pin);
    }
    sensorADC = sensorADC >> 5;
    sensorRatio = (float)ADC_VALUE_MAX / (float)sensorADC - 1.0;
    sensorResistance  = RES_DIVIDER / sensorRatio;
    _sensorLight = MULT_VALUE / (float)pow(sensorResistance, POW_VALUE);
}

float TroykaLight::getLightLux() {
    return _sensorLight;
}

float TroykaLight::getLightFootCandles() {
    return _sensorLight / LUX_TO_FOOT_CANDLES;
}