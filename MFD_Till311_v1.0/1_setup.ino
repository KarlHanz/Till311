void setup() {

  // настройка пинов на выход
  for (int a = 0; a < 4; a++) {
    pinMode(data[a], OUTPUT);  //set data lines outputs
    digitalWrite(data[a], LOW);
  }
  for (int a = 0; a < 6; a++) {
    pinMode(latches[a], OUTPUT);  //set latches outputs
    digitalWrite(latches[a], LOW);
  }
  for (int a = 0; a < 6; a++) {
    pinMode(blanking[a], OUTPUT);  //set blanking outputs
    digitalWrite(blanking[a], HIGH); // включить индикаторы
  }
  pinMode(PIEZO, OUTPUT);

  attachInterrupt(0, isr, CHANGE); // прерывание от кнопки
  butt1.setTimeout(3000);      // настройка таймаута на удержание



  // RTC
  rtc.begin();
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(2022, 01, 01, 12, 00, 0)); // произвольная дата при сбое питания
  }

  Watchdog.enable(RST_MODE, WDT_TIMEOUT_4S); // Режим сторжевого сброса , таймаут ~4с

  rtc.writeSqwPinMode(DS3231_SquareWave1Hz); //задать режим пина для мигания точки
  // rtc.writeSqwPinMode(DS3231_OFF); //задать режим пина для ВЫКЛ мигания точки




  // установка 16-ти битного Таймера1 для динамической индикации
  // https://habr.com/ru/post/453276/
  //сделал помедленнее (коэф.деления = 1024)

  TCCR1A = 0;
  TCCR1B = 0;                                       //начальное значение
  OCR1A = 100;                                     // установка регистра совпадения //должен быть меньше 65535 (в случае исп переполнения таймера)
  TCCR1B |= (1 << WGM12);                           // CTC режим - по совпадению
  TIMSK1 |= (1 << OCIE1A);                          // включение прерываний по совпадению
  TCCR1B |= (1 << CS10) | (0 << CS11) | (1 << CS12);   // запуск с таймера с делителем на 1024

}
