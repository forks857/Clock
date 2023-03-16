#include <stdio.h>
#include <time.h>
#include <unistd.h>

int currentTime(int *time, int period, int currentPeriod) {
  while (1) {
    if (*time >= period) {
      *time -= period;
      currentPeriod++;
    } else if (*time < period) {
      break;
    }
  }
  return currentPeriod;
}
const int second = 1;
const int minute = 60;
const int hour = 3600;
const int day = 86400;
const int month[2][12] = {
    {2678400, 5097600, 7776000, 10368000, 13046400, 15638400, 18316800, 20995200, 23587200, 26265600, 28857600, 3153600},
    {2678400, 5184000, 7862400, 10454400, 13132800, 15724800, 18403200, 21081600, 23673600, 26352000, 28944000, 31622400}};
const int year = 31536000;
const int leapYear = 31622400;
int main(void) {

  // set to PST during DST
  int timezone = -7;
  int military = 0;
  /*
  printf("Current timezone? (PST would be -8 without DST, -7 with)\n");
  scanf("%d", &timezone);
  printf("Enter 1 for 24 hour clock, anything else for 12 hour clock.\n");
  scanf("%d", &military);
  */
  while (1) {
    int hello;
    if (hello != time(NULL)) {
      printf("\033[0;0H\033[2J"); // This clears the console so it can refresh
      hello = time(NULL);
      // Bob is used to manipulate the time without touching its actual value
      int Bob = hello;
      Bob += (timezone * hour);
      int *Joe = &Bob;
      int leapDays = 0;
      int currentYear = 1970;
      int currentLeapYear = 0;
      int currentMonth = 0;
      int currentDay = 1;
      int currentHour = 0;
      int currentMinute = 0;
      int currentSecond = 0;
      while (1) {
        if (currentYear % 4 == 0) {
          Bob -= leapYear;
          currentYear++;
          leapDays++;
        } else {
          Bob -= year;
          currentYear++;
        }
        if (leapYear >= Bob && year <= Bob && currentYear % 4 == 0) {
          currentLeapYear = 1;
          break;
        } else if (year >= Bob) {
          currentLeapYear = 0;
          break;
        }
      }
      for (int i = 0; i < 12; i++) {
        if (month[currentLeapYear][i] > Bob) {
          currentMonth = i + 1;
          Bob -= month[currentLeapYear][i - 1];
          break;
        }
      }

      currentDay = currentTime(Joe, day, currentDay);
      currentHour = currentTime(Joe, hour, currentHour);

      if (!(military) && currentHour > 12) {
        currentHour -= 12;
      }

      currentMinute = currentTime(Joe, minute, currentMinute);
      currentSecond = currentTime(Joe, second, currentSecond);
      printf("Current time is %d:", currentHour);
      if (currentMinute < 10) {
        printf("0%d:", currentMinute);
      } else {
        printf("%d:", currentMinute);
      }
      if (currentSecond < 10) {
        printf("0%d\n", currentSecond);
      } else {
        printf("%d\n", currentSecond);
      }
      printf("Current date is %d/%d/%d \n", currentMonth, currentDay,
             currentYear);
      // Since apparently the sleep() function can only use seconds, we have to
      // use the usleep() function, which takes microseconds. right now, it is 1
      // millisecond
      usleep(1000);
    } else {
      usleep(1000);
    }
  }
}