
// динамическая индикация в прерывании таймера 1
ISR(TIMER1_COMPA_vect) {

  setPin(latches[curIndi], 1);         // зафиксировать показания на прошлом индикаторе

  if (++curIndi >= 6) curIndi = 0;  // перебор индикаторов по кругу

  byte thisDig = indiDigits[curIndi]; // предвывод цифры из массива indiDigits на следующий индикатор
  setPin(data_A, bitRead(thisDig, 0));
  setPin(data_B, bitRead(thisDig, 1));
  setPin(data_C, bitRead(thisDig, 2));
  setPin(data_D, bitRead(thisDig, 3));
  setPin(latches[curIndi], 0);         // отобразить предвывод на этом индикаторе!
}


void isr() {
  butt1.tick();  // опрашиваем в прерывании, чтобы поймать нажатие в любом случае
}


/*
  indiDigits[0] = 0xA; //старший разряд
  indiDigits[1] = 0xB; //
  indiDigits[2] = 0xC;
  indiDigits[3] = 0xD;
  indiDigits[4] = 0xE; //
  indiDigits[5] = 0xF; //младший разряд
  }
*/
