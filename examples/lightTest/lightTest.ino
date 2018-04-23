// библиотека для работы с датчиком освещённости (Troyka-модуль)
#include <TroykaLight.h>

// создаём объект для работы с датчиком освещённости
// и передаём ему номер пина выходного сигнала
TroykaLight sensorLight(A0);

void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
}

void loop()
{
  // считывание данных с датчика освещённости
  sensorLight.read();
  // вывод показателей сенсора освещённости в люксахи
  Serial.print("Light is ");
  Serial.print(sensorLight.getLightLux());
  Serial.print(" Lx\t");
  // вывод показателей сенсора освещённости в фут-свечах
  Serial.print(sensorLight.getLightFootCandles());
  Serial.println(" Foot Candles");
  delay(300);
}
