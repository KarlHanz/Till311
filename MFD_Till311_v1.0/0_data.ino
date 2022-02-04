#include <Wire.h>
#include <RTClib.h>
#include "GyverHacks.h"
#include <GyverWDT.h>
#include "GyverButton.h"
GButton butt1(BTN1);

RTC_DS3231 rtc;

volatile int8_t data[4] = {data_A, data_B, data_C, data_D}; // массив линий шины данных
volatile int8_t latches[6] = {CS0, CS1, CS2, CS3, CS4, CS5}; // массив линий шины защелок
byte blanking[6] = {BL0, BL1, BL2, BL3, BL4, BL5}; // массив линий шины гашения индикаторов

int8_t mode = 0;    // 0 - часы, 1 - температура, 2 - RS-485
int8_t yyyy, mm, dd, hrs, mins, secs;
byte znak;
int temp;
float temp_in;
float temp_out;
int8_t modes = 1; 

byte n1;
byte n2;
byte n3;
byte n4;

volatile int8_t indiDigits[6];    // цифры и знаки, которые должны показать все 6 индикаторов (0-F)
volatile int8_t curIndi;          // текущий индикатор (0-5)
volatile int8_t indiCounter;     // счётчик
