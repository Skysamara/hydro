void setup(void)
{

  Serial.begin(115200);
  delay(100);

  pinMode(term_power, OUTPUT);
  digitalWrite(term_power, HIGH);

  pinMode(DHTPin, INPUT);

  //  readSettings();


  dht.begin();
  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, timerEvent);

//  bool b = 1;
//  float f = 100000;
//  int i = 5;
//  Serial.print("***** b *****");
//  Serial.println(sizeof(b));
//
//  Serial.print("***** f *****");
//  Serial.println(sizeof(f));
//
//  Serial.print("***** i *****");
//  Serial.println(sizeof(i));
//
//  EEPROM.begin(512);

//  CreateObjects();
  readSettings();
  pump1.Stop();

}
