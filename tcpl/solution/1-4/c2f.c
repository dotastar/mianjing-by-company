#include <stdio.h>

main()
{
  float celsius, fahr;
  int lower, upper, step;
  lower = 0;
  upper = 100;
  step = 10;
  celsius = lower;
  printf("convert from celsius to fahr\n");
  while(celsius <= upper) {
    fahr = celsius * 9.0 / 5.0 - 32;
    printf("%3.0f %6.2f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
