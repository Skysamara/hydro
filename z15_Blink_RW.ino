

BLYNK_WRITE(V0) // Длительность полива первой помпы
{
  setPumpDuration(param.asInt());
}

BLYNK_WRITE(V1) // Установка времени старта полива
{
  // You'll get HIGH/1 at startTime and LOW/0 at stopTime.
  // this method will be triggered every day
  // until you remove widget or stop project or
  // clean stop/start fields of widget

  Serial.print("Таймер: ");
  //  Serial.println(pump1.GetCurrentDuration());

  //  pump1.Start();
}

BLYNK_WRITE(V4) // Кнопка помпы 1
{
  if (param.asInt() == 0) {
    pump1.Stop();
  }
  else {
    pump1.Start();
  }
}
