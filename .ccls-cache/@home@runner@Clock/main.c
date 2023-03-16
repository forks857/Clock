#include <stdio.h>
#include <time.h>
#include <unistd.h>

int Steve(int *Bob,int period, int currentPeriod) {
  while(1) {
   if (*Bob >= period) {
      *Bob -= period;
      currentPeriod++;
}  else if (*Bob < period) {
           break;
        }
  } return currentPeriod;
  }
    int main(void)
    {
//At this point, it is a couple of seconds behind some other clocks, but I think this is more accurate. updates within a millisecond, could be improved but would have to run more often and I don't yet know the impact of that. could also probably add milliseconds by just running this every millisecond and adding one
      //Generalize some of the other bits with a function, specifically day, hour, minute, and second. other values can be returned by using pointers
      //apparently, variables declared inside an if statement or anything else with brackets are only able to be used within that statement and its children, not its parents.
      //Time at 20:30:35 on Jan 31, 2023 -8 UTC is 1675225835, for testing purposes.

      const int second = 1;
      const int minute = 60;
      const int hour = 3600;
      const int day = 86400;
      const int month[2][12] = {{2678400, 5097600, 7776000, 10368000, 13046400, 15638400, 18316800, 20995200, 23587200, 26265600, 28857600, 3153600}, {2678400, 5184000, 7862400, 10454400, 13132800, 15724800, 18403200, 21081600, 23673600, 26352000, 28944000, 31622400}};
      const int year = 31536000;
      const int leapYear = 31622400;
      //set to PST during DST
      int timezone = -7; 
      int military = 0;
      /*
        printf("Current timezone? (PST would be -8 without DST, -7 with)\n");
     scanf("%d", &timezone);
     printf("Enter 1 for 24 hour clock, anything else for 12 hour clock.\n");
        scanf("%d", &military);
      */
      while(1) {
        int hello;
        if(hello != time(NULL)) {
        printf("\033[0;0H\033[2J"); //This clears the console so it can refresh
        hello = time(NULL);
        //Bob is used to manipulate the time without touching its actual value
        int Bob = hello;
        Bob += (timezone * hour);
        int* Joe = &Bob; //Joe is a pointer to Bob
        printf("%p\n", Joe);
        int leapDays = 0;
        int currentYear = 1970;
        int currentLeapYear = 0;
        int currentMonth = 0;
        int currentDay = 1;
        int currentHour = 0;
        int currentMinute = 0;
        int currentSecond = 0;
        while (1) {
          if (currentYear % 4 == 0)  { 
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
        } else if ( year >= Bob) {
          currentLeapYear = 0;
          break;
        }
      }
      //don't need to do a check because if it is a leap year, currentLeapYear will have a value of 1 in the array, and if it isn't, currentLeapYear will have a value of 0 in the array
      int i = 0;
      while(1) {
        if (month[currentLeapYear][i] > Bob) {
          currentMonth = i + 1; 
          Bob -= month[currentLeapYear][i-1];
          break;
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
      if (military != 1 && currentHour > 12) {
        currentHour -= 12;
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
      //Since apparently the sleep() function can only use seconds, we have to use the usleep() function, which takes microseconds. right now, it is 1 millisecond 
      usleep(1000);
      } else {
        usleep(1000);
      }
    }
  }