/****************************************************************************/
//  Function:       Header file for TroykaLight
//  Hardware:       GL5528
//  Arduino IDE:    Arduino-1.6.11
//  Author:         Igor Dementiev
//  Date:           Feb 28,2017
//  Version:        v1.0
//  by www.amperka.ru
/****************************************************************************/

#ifndef TROYKA_LIGHT_H_
#define TROYKA_LIGHT_H_

#include <Arduino.h>

class LIGHT
{
public:
    LIGHT(uint8_t pin);
    float readLight();
private:
    uint8_t _pin;
};
#endif  // TROYKA_LIGHT_H_
