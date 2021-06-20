class Pump
{
    unsigned long lastTime;
    int duration = 10; // Время полива **************************

    int  maxDuration;  // Максимальное время полива
    int  currentDuration; // Текущее время полива для отображения в приложении

  public:
    Pump(uint8_t address, uint8_t motor, uint32_t freq) { 
      _m = new Motor(address, motor, freq);
      lastTime = millis();
      currentDuration = 0;
      Serial.println("Pump created");
    }

    void Update() {
//      if ((millis() - lastTime) > duration * 1000)  // Пора выключать
//      {
//        lastTime = millis();
//        Serial.println("Update-stop");
//        _m -> setmotor(_STOP);
//      }
    }

    void Start() {
      //      if (!IsON())
      //      {
      Serial.print("Start! ");
      Serial.println(duration);
      lastTime = millis();
      _m -> setmotor(_CCW, 100);
//      Update();
      //      }
    }

    void Stop() {
      //      if (IsON())
      //      {
      Serial.print("Stop! ");
      Serial.println(duration);
      lastTime = millis();
      _m -> setmotor(_STOP);
//      Update();
      //      }
    }

    int GetCurrentDuration() {
      //      if (IsON()) // Если помпа включена
      //      {
      return ((millis() - lastTime) / 1000);  // Текущее время полива
      //      }
      //      else
      //      {
      //        return 0;
      //      }
    }

    void SetDuration(int d) {
      duration = d;
      Serial.print("SetDuration ");
      Serial.println(duration);
    }

  private:
    Motor *_m;
};
