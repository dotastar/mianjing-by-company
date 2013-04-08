#include <stdio.h>

static char daytab[2][13] = {
  {0,31,28,31,30,31,30,31,31,30,31,30,31},
  {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year, int month, int day) {
  int i, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  if(month < 1 || month > 12){
    printf("month is out of range!\n");
    return 0;
  }
  if(day < 1 || day > daytab[leap][month]){
    printf("day is out of range!\n");
    return 0;
  }

  for(i = 1; i < month; ++i) {
    day += daytab[leap][i];
  }
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  if(yearday < 1 || yearday > (leap?366:365)){
    printf("day is out of range!\n");
    return;
  }
  
  for(i = 1; yearday > daytab[leap][i]; ++i) {
    yearday -= daytab[leap][i];
  }
  *pmonth = i;
  *pday = yearday;
}

int main() {
  printf("(1980-2-29)=%d\n", day_of_year(1980, 6, 11));
  int month = 0;
  int day = 0;
  month_day(1980, 366, &month, &day);
  printf("(1980-61)=%d, %d\n", month, day);
  return 0;
}
