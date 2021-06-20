void setup(void)
{

  Serial.begin(115200);
  delay(100);
//
  pinMode(term_power, OUTPUT);
  digitalWrite(term_power, HIGH);

  pinMode(DHTPin, INPUT);

  dht.begin();
  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, timerEvent);

  readSettings();
  pump1.Stop();

}
