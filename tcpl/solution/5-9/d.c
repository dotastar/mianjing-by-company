#include <stdio.h>

static char daytab[2][13] = {
  {0,31,28,31,30,31,30,31,31,30,31,30,31},
  {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year, int month, int day) {
  int i, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

  char *p = daytab[leap];
  while(month-- > 1)
    day += *++p;
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

  char *p = daytab[leap];
  while(yearday > *++p){
    yearday -= *p;
  }
  *pmonth = p - daytab[leap];
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
