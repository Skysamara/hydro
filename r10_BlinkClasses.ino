class Pump
{
    unsigned long lastTime;
    int duration = 10; // Время полива **************************

    int  maxDuration = 600;  // Максимальное время полива 10 минут
    int  currentDuration; // Текущее время полива для отображения в приложении

  public:
    Pump(uint8_t address, uint8_t motor, uint32_t freq) {
      _m = new Motor(address, motor, freq);
      lastTime = millis();
      currentDuration = 0;
      Serial.println("Pump created");
    }

    void Update() {
      if (((millis() - lastTime) > duration * 1000)   // истекло установленное время
          || ((millis() - lastTime) > maxDuration * 1000))// или превышено максимальное
      {
        lastTime = millis();
        Serial.println("class Pump. void Stop()");
        _m -> setmotor(_STOP);
      }
    }

    void Start() {
      //      if (!IsON())
      //      {
      Serial.print("class Pump. void Start()  ");
      Serial.println(duration);
      lastTime = millis();
      _m -> setmotor(_CCW, 100);
    }

    void Stop() {
      //      if (IsON())
      //      {
      Serial.print("class Pump. void Stop() ");
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
      Serial.print("void SetDuration(int d): ");
      Serial.println(duration);
    }

  private:
    Motor *_m;
};
