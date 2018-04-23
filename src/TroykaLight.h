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

#if defined(__AVR__)
#define OPERATING_VOLTAGE   5.0

#elif defined(__SAM3X8E__) || defined(__SAM3A8C__) || defined(__SAM3A4C__) || defined(__SAMD21G18A__) || defined(ARDUINO_ARCH_ESP8266) || defined(__arm__)
#define OPERATING_VOLTAGE   3.3
#endif

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

