
/*
  Расположение индикаторов: 543.210
   TIL311 MCU
   Created: 09.03.2021
   Author : KarlHanz
  https://github.com/jh1995/til311-x4-clock
  https://github.com/tuupola/avr_demo/blob/605bfd3d655e31f418eaac2c47b073c25709c6ca/til311/main.c
  https://arduino-kit.ru/blogs/blog/project_07
  https://github.com/Makuna/Rtc/issues/49
  http://arduinolearning.com/code/reading-temperature-using-the-ds3231-rtc.php
  https://devpractice.ru/from-float-to-char-array-in-c-cpp/
  http://forum.amperka.ru/threads/%D0%9F%D0%BE%D0%BB%D1%83%D1%87%D0%B8%D1%82%D1%8C-float-%D0%BF%D0%BE-com.18706/
  https://adior.ru/index.php/robototekhnika/178-timer-interrupt
  https://habr.com/ru/post/453276/

  GyverWDT-main/GyverWDT.h - "вручную" добавлен ATMEGA328PB в список поддерживаемых МК, иначе не компилится.
*/

// BLANC pins connected
#define BL0 A0 // PC0 //если BL=0, индикатор выключается
#define BL1 A1 // PC1
#define BL2 A2 // PC2
#define BL3 A3 // PC3
#define BL4 A6 // PC6
#define BL5 A7 // PC7

// LATCH pins connected
#define CS0 8 // PB0 // если CS=1, индикатор "защёлкивается"
#define CS1 9 // PB1
#define CS2 10 // PB2
#define CS3 11 // PB3
#define CS4 12 // PB4
#define CS5 13 // PB5

// DATA pins connected
#define data_A 4 // PD4
#define data_B 5 // PD5
#define data_C 6 // PD6 
#define data_D 7 // PD7

// Button pin connected
#define BTN1 2 // PD2

// Buzzer pin connected
#define PIEZO 3 // PD3
