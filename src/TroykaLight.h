/****************************************************************************/
//  Function:       Header file for TroykaLight
//  Hardware:       GL5528
//  Arduino IDE:    Arduino-1.8.3
//  Author:         Igor Dementiev
//  Date:           Apr 19,2018
//  Version:        v1.0.0
//  by www.amperka.ru
/****************************************************************************/

#ifndef TROYKA_LIGHT_H_
#define TROYKA_LIGHT_H_

#include <Arduino.h>

// resistance other resistor for divider (Ohm)
#define RES_DIVIDER         10000.0
#define MULT_VALUE          32017200.0
#define POW_VALUE           1.5832
#define LUX_TO_FOOT_CANDLES 10.764

#define SAMPLE_TIMES        32
#define ADC_BIT             10
#define ADC_VALUE_MAX       pow(2, ADC_BIT)

class TroykaLight
{
public:
    TroykaLight(uint8_t pin);
    void read();
    float getLightLux();
    float getLightFootCandles();
private:
    uint8_t _pin;
    float _sensorLight;
};
#endif  // TROYKA_LIGHT_H_

