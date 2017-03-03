// библиотека для работы с датчиком освещённости (Troyka-модуль)
#include <TroykaLight.h>

// создаём объект для работы с датчиком освещённости
// и передаём ему номер пина выходного сигнала
LIGHT sensorLight(A4);

void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
}

void loop()
{
  // вывод показателей сенсора освещённости в люксах
  Serial.print("Light is ");
  Serial.print(sensorLight.readLight());
  Serial.println(" Lx");
  delay(100);
}
