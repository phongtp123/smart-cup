#include "draw_module.h"
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <U8g2lib.h>
#include "HX711.h"

void setup() {
  pinMode(SENSOR_MENU, INPUT);
  pinMode(SENSOR_LEFT, INPUT);
  pinMode(SENSOR_RIGHT, INPUT);
  pinMode(SENSOR_ENTER, INPUT);
  pinMode(SENSOR_ON, INPUT);
  pinMode(STATUS_SENSOR_PIN, INPUT);
  bool parse=false;
  bool config=false;
  if (getDate(__DATE__) && getTime(__TIME__)) {
    parse = true;
    // and configure the RTC with this info
    if (RTC.write(tm)) {
      config = true;
    }
  }
  u8g2.begin(); 
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN); 
  scale.set_scale(-385.421); 
  scale.tare(0);
  u8g2.enableUTF8Print(); 
  Serial.begin(115200);
  while (!Serial) ; // wait for Arduino Serial Monitor
  delay(200);
  if (parse && config) {
    Serial.print("DS1307 configured Time=");
    Serial.print(__TIME__);
    Serial.print(", Date=");
    Serial.println(__DATE__);
  } else if (parse) {
    Serial.println("DS1307 Communication Error :-{");
    Serial.println("Please check your circuitry");
  } else {
    Serial.print("Could not parse info from the compiler, Time=\"");
    Serial.print(__TIME__);
    Serial.print("\", Date=\"");
    Serial.print(__DATE__);
    Serial.println("\"");
  }
}

void loop() { 
  handleInput();
  RTCDrop();
  execution();
}
