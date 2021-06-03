//////////////////////////////////////////////////////////////
class Pump
{
    int pin;  // Куда подключен
    unsigned long lastTime;
    int duration; // Время полива

    int  maxDuration;  // Максимальное время полива
    int  currentDuration; // Текущее время полива для отображения в приложении

  public:
    Pump(int p) // Пин
    {
      pin = p;
      pinMode(pin, OUTPUT);
      digitalWrite(pin, HIGH); // При создании выключена // Инверсия

      lastTime = millis();
      currentDuration = 0;
    }

    void Update()
    {
      if ((millis() - lastTime) > duration * 1000)
      {
        digitalWrite(pin, HIGH); // Инверсия
      }
    }

    void Start()
    {
      if (!IsON())
      {
        Serial.print("Start! ");
        Serial.println(duration);
        lastTime = millis();
        digitalWrite(pin, LOW); // Инверсия
        Update();
      }
    }

    void Stop()
    {
      if (IsON())
      {
        Serial.print("Stop! ");
        Serial.println(duration);
        lastTime = millis();
        digitalWrite(pin, HIGH); // Инверсия
        Update();
      }
    }

    boolean IsON()  // Текущее состояние
    {
      if (digitalRead(pin) == LOW) // Инверсия
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    int GetCurrentDuration()
    {
      if (IsON()) // Если помпа включена
      {
        return ((millis() - lastTime) / 1000);  // Текущее время полива
      }
      else
      {
        return 0;
      }
    }

    void SetDuration(int d)
    {
      duration = d;
      Serial.print("SetDuration ");
      Serial.println(duration);
    }
};
//////////////////////////////////////////////////////////////

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#include "WEMOS_Motor.h"
#include <EEPROM.h>

//char auth[] = "Fdj2ndHfZmRirtgrgdrfh81fzPpfB0-"; // origin
//char ssid[] = "WIFI";
//char pass[] = "132password";

#include "auth.h"
 

BLYNK_CONNECTED() {
  // Request Blynk server to re-send latest values for all pins
  Blynk.syncAll();
}

#define DHTTYPE DHT22
#define DHTPin 0  //D3 DHT датчик
#define term_power 4 //D2
#define led_pin 2 // D4
  //#define pump1_pin 3 // ??????????D4

  boolean led_status = 0;
  float Temperature;
  float Humidity;

  DHT dht(DHTPin, DHTTYPE); // Инициализация датчика DHT
  BlynkTimer timer;

  //  Pump pump1(pump1_pin);
  Pump pump1(led_pin);

  Motor M1(0x30,_MOTOR_A, 1000); // Помпа

  /////////////////////////////////////////////////////////////
  // BLYNK_WRITE() на первой вкладке, по-другому не работает //
  /////////////////////////////////////////////////////////////

  BLYNK_WRITE(V0) // Длительность полива первой помпы
  {
    int d = param.asInt();
    pump1.SetDuration(d);
    Serial.print("Длительность: ");
    Serial.println(d);
  }

  BLYNK_WRITE(V1) // Таймер
  {
    // You'll get HIGH/1 at startTime and LOW/0 at stopTime.
    // this method will be triggered every day
    // until you remove widget or stop project or
    // clean stop/start fields of widget

    Serial.print("Таймер: ");
    Serial.println(pump1.GetCurrentDuration());

    pump1.Start();
  }

  BLYNK_WRITE(V4) // Кнопка помпы 1
  {
    pump1.Start();
  }

  //BLYNK_WRITE(V5) // Таймер
  //{
  //  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  //  Serial.print("V1 Slider value is: ");
  //  Serial.println(pinValue);
  //  run_pump();
  //}
