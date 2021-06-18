#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#include "WEMOS_Motor.h"  
#include <EEPROM.h>

#include "auth.h"

#define DHTTYPE DHT22
#define DHTPin 0  //D3 DHT датчик
//#define term_power 4 //D2
#define term_power 16 //D0. D1, D2 заняты моторами
#define led_pin 2 // D4

boolean led_status = 0;
//float Temperature;
//float Humidity;

DHT dht(DHTPin, DHTTYPE); // Инициализация датчика DHT
BlynkTimer timer;

BLYNK_CONNECTED() {
  // Request Blynk server to re-send latest values for all pins
  blynk_connected(); 
}




//  Motor M1(0x2D,_MOTOR_A, 1000); // Адрес, мотор, частота
