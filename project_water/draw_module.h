#include <Wire.h>
#include <U8g2lib.h>
#include <Arduino.h>
#include <DS1307RTC.h>
#include <U8g2lib.h>

#ifndef DRAW_MODULE_H
#define DRAW_MODULE_H

// Khởi tạo U8g2 với driver SH1106, dùng chân I2C mặc định (SDA = A4, SCL = A5)
extern U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2;

extern tmElements_t tm;

bool getTime(const char *str);

bool getDate(const char *str);

void handleInput();

void drawLowFace();

void drawMiddleFace();

void drawOkayFace();

void drawHappyFace();

void drawBuck(int weight);

void drawDrop();

void level_bar();

void plan_menu();

void RTCDrop();

void execution();

#endif

