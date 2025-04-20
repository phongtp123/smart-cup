#include <Wire.h>
#include <U8g2lib.h>
#include <Arduino.h>
#include <DS1307RTC.h>
#include <U8g2lib.h>
#include "HX711.h"

#ifndef DRAW_MODULE_H
#define DRAW_MODULE_H
#define SENSOR_MENU 13
#define SENSOR_LEFT 12
#define SENSOR_RIGHT 14
#define SENSOR_ENTER 33
#define SENSOR_ON 4
#define STATUS_SENSOR_PIN 15
#define LOADCELL_DOUT_PIN 26
#define LOADCELL_SCK_PIN 27
// PCA9548A I2C Multiplexer address
#define PCA9548A_ADDR 0x70
// Define all I2C device channel connect to multiplexer
#define OLED1_CHANNEL 3
#define DS1307_CHANNEL 2

// Khởi tạo U8g2 với driver SH1106, dùng chân I2C mặc định (SDA = A4, SCL = A5)
extern U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2;

// Khởi tạo HX711
extern HX711 scale;

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

