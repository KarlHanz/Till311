void loop() {
  butt1.tick();  // опрашиваем в скетче, иначе не будут работать проверки по времени!

  DateTime now = rtc.now();
  dd = now.day();
  mm = now.month();
  yyyy = now.year();
  hrs = now.hour();
  mins = now.minute();
  secs = now.second();
  
  temp = rtc.getTemperature(); // ФУНКЦИЯ отображения температуры корректно НЕ РАБОТАЕТ!
  if (temp < 0) znak = 0xF;
  else znak = 0xA;
  float float_data = abs(temp);   //убираем минус

  String s = String(float_data, BIN);
  byte i = s.indexOf('.'); //поиск точки "." Возвращает её место (1 или 2)
  if (i >= 0) s.remove(i, 1); //  Возвращает новую строку, в которой удалён 1 символ в позиции i
  if (i == 2) { //float 10.00
    n1 = s.substring(0, 1).toInt();
    n2 = s.substring(1, 2).toInt();
    n3 = s.substring(2, 3).toInt();
    n4 = s.substring(3).toInt();
  }
  if (i == 1) { //float 0.00 //включить BLANK в этот разряд
    n1 = 0;
    n2 = s.substring(0, 1).toInt();
    n3 = s.substring(1, 2).toInt();
    n4 = s.substring(2, 3).toInt();
  }




if (butt1.isHolded()) rtc.adjust(DateTime(2022, 01, 31, 22, 27, 0)); // дата


  if (butt1.isClick()) { // кнопка MODE (по кольцу)
    modes++;
    if (modes > 4) modes = 1;
  }
  switch (modes) {   // Часы с секундами -> Часы без секунд -> Дата
    case 1: // Часы с секундами
      rtc.writeSqwPinMode(DS3231_OFF); //задать режим пина для ВЫКЛ мигания точки
      digitalWrite(BL0, LOW); // включить индикатор 0
      digitalWrite(BL1, LOW); // включить индикатор 1
      digitalWrite(BL2, LOW); // включить индикатор 2
      digitalWrite(BL3, LOW); // включить индикатор 3
      digitalWrite(BL4, LOW); // включить индикатор 4
      digitalWrite(BL5, LOW); // включить индикатор 5
      indiDigits[0] = hrs / 10;
      indiDigits[1] = hrs % 10;
      indiDigits[2] = mins / 10;
      indiDigits[3] = mins % 10;
      indiDigits[4] = secs / 10;
      indiDigits[5] = secs % 10;
      break;
    case 2: // Часы без секунд
      rtc.writeSqwPinMode(DS3231_SquareWave1Hz); //задать режим пина для ВКЛ мигания точки
      digitalWrite(BL0, HIGH); // вЫключить индикатор 0
      digitalWrite(BL1, LOW); // включить индикатор 1
      digitalWrite(BL2, LOW); // включить индикатор 2
      digitalWrite(BL3, LOW); // включить индикатор 3
      digitalWrite(BL4, LOW); // включить индикатор 4
      digitalWrite(BL5, HIGH); // вЫключить индикатор 5
      indiDigits[0] = 0x0; //старший разряд
      indiDigits[1] = hrs / 10;
      indiDigits[2] = hrs % 10;
      indiDigits[3] = mins / 10;
      indiDigits[4] = mins % 10;
      indiDigits[5] = 0x0; //младший разряд
      break;
    case 3: //Дата со служебными символами
      rtc.writeSqwPinMode(DS3231_OFF); //задать режим пина для ВЫКЛ мигания точки
      digitalWrite(BL0, LOW); // включить индикатор 0
      digitalWrite(BL1, LOW); // включить индикатор 1
      digitalWrite(BL2, LOW); // включить индикатор 2
      digitalWrite(BL3, LOW); // включить индикатор 3
      digitalWrite(BL4, LOW); // включить индикатор 4
      digitalWrite(BL5, LOW); // включить индикатор 5
      indiDigits[0] = 0xD; //старший разряд
      indiDigits[1] = dd / 10;
      indiDigits[2] = dd % 10;
      indiDigits[3] = mm / 10;
      indiDigits[4] = mm % 10;
      indiDigits[5] = 0xF; //младший разряд
      break;
    case 4: //Температура
      rtc.writeSqwPinMode(DS3231_OFF); //задать режим пина для ВЫКЛ мигания точки
      digitalWrite(BL0, LOW); // включить индикатор 0
      digitalWrite(BL1, LOW); // включить индикатор 1
      digitalWrite(BL2, LOW); // включить индикатор 2
      digitalWrite(BL3, LOW); // включить индикатор 3
      digitalWrite(BL4, LOW); // включить индикатор 4
      digitalWrite(BL5, LOW); // включить индикатор 5
      indiDigits[0] = znak;
      indiDigits[1] = n1;
      indiDigits[2] = n2;
      indiDigits[3] = n3;
      indiDigits[4] = n4;
      indiDigits[5] = 0xC; //младший разряд
      break;


  }



  Watchdog.reset(); // Переодический сброс watchdog

}
