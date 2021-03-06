void sleep(){
  delay (200);
  ESP.deepSleep(timeSleep);
}

void timerEvent()
{
  read_DHT22();
  refreshApp();
}

void refreshApp()
{
  while (Blynk.connect() == false){}; // Ждём подключения
  Blynk.virtualWrite(V5, pump1.GetCurrentDuration());
}



void read_DHT22()
{
  while (Blynk.connect() == false){}; // Ждём подключения
  float Temperature = dht.readTemperature();
  float Humidity = dht.readHumidity();

  //    Serial.print("Температура: ");
  //    Serial.println(Temperature, 2);
  //    Serial.print("Влажность: ");
  //    Serial.println(Humidity, 2);

  Blynk.virtualWrite(V3, Temperature);
  Blynk.virtualWrite(V2, Humidity);
}

void setPumpDuration(int v0) {
  int d = v0;
  pump1.SetDuration(d);
  Serial.print("setPumpDuration(int v0): ");
  Serial.println(d);
}

void blynk_connected() {
  Blynk.syncAll();
}

//  void writeSettings(){  // Для сохранения настроек в EEPROM
//  EEPROM.update(0, pump1.GetCurentDuration();
//}

void readSettings() {
  //  int f = 0;
  //  EEPROM.get(0, f);
  //  pump1.setDuration(f);
  //  Serial.print("EEPROM.get(0, f): ");
  //  Serial.println(f, 2);
  //
  //  EEPROM.write(0, 15);
  //  EEPROM.get(0, f);
  //  Serial.print("EEPROM.write(0, f): ");
  //  Serial.println(f, 2);
}
