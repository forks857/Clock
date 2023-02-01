#include <stdio.h>
#include <time.h>
#include <unistd.h>
    int main(void)
    {
      //to check time you could either wait until theres a change, or do progressive checking: wait 0.1 seconds to find the change, then wait 0.9 seconds before checking every 0.01 seconds for a change, etc. waiting once may be simpler in the long run.
      //either the chromebook is slightly off or this is slightly fast.
//At this point, it is accurate. the next steps are probably going to be:
      //going through comments and deleting them, 
      //going through and seeing if it can be shortened in some way. 
      //Time at 20:30:35 on Jan 31, 2023 -8 UTC is 1675225835

      const int second = 1;
      const int minute = 60;
      const int hour = 3600;
      const int day = 86400;
      const int month[2][12] = {{2678400, 5097600, 7776000, 10368000, 13046400, 15638400, 18316800, 20995200, 23587200, 26265600, 28857600, 3153600}, {2678400, 5184000, 7862400, 10454400, 13132800, 15724800, 18403200, 21081600, 23673600, 26352000, 28944000, 31622400}};
      const int year = 31536000;
      const int leapYear = 31622400;
 //Bob is used to manipulate the time without touching its actual value

      int timezone;
      //all above values are in seconds. 
      printf("Current timezone? (PST would be -8, for instance)\n");
      scanf("%d", &timezone);
      //add in a military/normal time version, also add in an array of timezone names

      while(1) {
        int hello;
        if(hello != time(NULL)) {
        printf("\033[0;0H\033[2J");
        hello = time(NULL);
        int Bob = hello;
        Bob += (timezone * hour);
        int leapDays = 0;
        int currentYear = 1970;
        int currentLeapYear = 0;
        int currentMonth = 0;
        int currentDay = 1;
        int currentHour = 0;
        int currentMinute = 0;
        int currentSecond = 0;
        while (1) {
          if (currentYear % 4 == 0)  { //if it's a leap year
            Bob -= leapYear;
            currentYear++;
            leapDays++;
          } else { //if it isn't a leap year
            Bob -= year;
            currentYear++;
          }
        //this if statement should probably be looked at more
        if (leapYear >= Bob && year <= Bob && currentYear % 4 == 0) {
          break;
          currentLeapYear = 1;
        } else if ( year >= Bob) {
          currentLeapYear = 0;
          break;
        }
      }
      //set a loop for months here(include checking leap years) don't need to do a check because if it is a leap year, currentLeapYear will be #1 in the array, and if it isn't, currentLeapYear will be #0 in the array
      int i = 0;
      while(1) {
        //months may be the reason that days are off, because I don't know what else could cause it. 
        if (month[currentLeapYear][i] > Bob) {
          currentMonth = i + 1; //+1 is only because arrays start at 0
          Bob -= month[currentLeapYear][i-1];
          break;
          //subtracts the previous month's total 
        } else {
          i++;
        }
        if (i == 11) {
          break;
        }
      } 

      
      while(1) {
       if (Bob >= day) {
         Bob -= day;
         currentDay++;
       } else {
           break;
        }
       }
      while(1) {
       if (Bob >= hour) {
         Bob -= hour;
         currentHour++;
       } else {
           break;
        }
       }
      while(1) {
       if (Bob >= minute) {
         Bob -= minute;
         currentMinute++;
       } else {
           break;
        }
       }
      while(1) {
       if (Bob >= second) {
         Bob -= second;
         currentSecond++;
       } else if (Bob < second) {
           break;
        }
       }
      printf("Current time is %d:", currentHour);
        if(currentMinute < 10) {
          printf("0%d:", currentMinute);
        } else {
          printf("%d:", currentMinute);
        }
        if(currentSecond < 10) {
          printf("0%d\n", currentSecond);
        } else {
          printf("%d\n", currentSecond);
        }
      printf("Current date is %d/%d/%d \n", currentMonth, currentDay, currentYear);
      //Since apparently the sleep() function can only use seconds, we have to use the usleep() function, which takes microseconds.
      usleep(100000);
      } else {
        usleep(100000);
      }
      // print \033[0;0H\033[2J to clear the console (https://replit.com/talk/ask/Clearing-a-screen-in-replit-for-the-C-language/15256)
    }
  }