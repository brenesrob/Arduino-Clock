// Date and time functions using a DS1307 RTC connected via I2C and Wire lib

//Include all needed libraries
#include <Wire.h>
#include "RTClib.h" //must be downloaded
#include <LiquidCrystal.h>
#include <CapacitiveSensor.h> //must be downloaded
#include <Tone.h>


boolean snooze_button_state;
boolean select,up, right, down,left;
int seconds;
int minutes;
int hours;
int x = 0;
int currx = 1023;
long non=0;
boolean ledState=LOW;
long interval = 1000;


// time when snooze period should end:
int snooze_off_hours;
int snooze_off_minutes;

//Alarm variables                                  
boolean  alarm_on = true;
boolean signal_on = false;
boolean snooze_on = false;
unsigned long snooze_button_timer; 
// alarm time:
int alarm_hours=0;
int alarm_minutes=0;

RTC_DS1307 RTC;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup () {
    lcd.begin(16, 2);
    lcd.clear();
    Wire.begin();
    RTC.begin();

if(! RTC.isrunning()){
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));}
  
}

void loop () {
  

clock();

  
 
    
}
