/*

Pomodoro timer to keep track of Work and Rest.

Inspired by https://www.hackster.io/hugonator/pomodoro-timer-with-an-arduino-and-an-lcd-screen-3d469e (Hugo Blanc)

*/

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int work = 25;
const int rest = 5;

char tl[32];
short int mins, secs;
short int i = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Time:");
}

void loop() {
  lcd.setCursor(0, 1);
  sprintf(tl, "%2d mins %2d secs", mins, secs);
  lcd.print(tl);

  delay(1000);

  secs++;

  if (secs == 60) {
    secs = 0;
    mins ++;
  }

  if (mins == work && i == 0) {
    mins = 0;
    i = 1;
  } else if (mins == rest && i == 1) {
    mins = 0;
    i = 0;
    }
}
