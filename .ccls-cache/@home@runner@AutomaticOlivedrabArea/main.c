#include <stdio.h>
#include <time.h>

    int random_number(int min_num, int max_num);

    int main(void)
    {
      //it thinks that leap years start at 1970, not at 1968 or 1972, and also by default it starts at day 0 of month 0 in the year 0 at 00:00. In reality, it should start at day 1 of month 1 in the year 1970, at 00:00(12am) 
      //Currently(in 2023) the leap year thing doesn't matter; it only really does between 
      int hi = time(NULL);
      int hello = hi;
      double minute = 60;
      double hour = 60 * minute;
      double day = 24 * hour ;
      double year = 365.25 * day;
      double cYear = (hello / year) + 1970;
      int currentYear = cYear;
      double cMonth = ((cYear - currentYear) * 12) + 1;
      int currentMonth = cMonth;
      //Add a for loop for the modulo of years with 0 from 1970
      for(i = )
      double cDay = (hello / day) - ((currentYear - 1970) * 365.25) + 1;
      int currentDay = cDay;
      int daysPassed = hello / 86400;
      printf("%d current time \n", hello);
      printf("%d current year \n", currentYear);
      printf("%f current year(precise) \n", cYear);
      printf("%d current month \n", currentMonth);
      printf("%f current month(precise) \n", (cYear - currentYear) * 12);
      printf("%d current day\n", currentDay);
      printf("%f current day(precise)\n", cDay);
      printf("%d days passed", daysPassed);
    }