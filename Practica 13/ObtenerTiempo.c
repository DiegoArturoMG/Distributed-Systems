#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#define SEC_PER_DAY   86400
#define SEC_PER_HOUR  3600
#define SEC_PER_MIN   60

int main() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  
  printf("Segundos  = %lld\n", (long long) tv.tv_sec);
  printf("Milisegundos  = %lld\n", (long long) tv.tv_usec);

  long hms = tv.tv_sec % SEC_PER_DAY;
  printf("HMS: %ld\n", hms);  
  // mod `hms` to insure in positive range of [0...SEC_PER_DAY)

  // Tear apart hms into h:m:s
  int hour = hms / SEC_PER_HOUR;
  int min = (hms % SEC_PER_HOUR) / SEC_PER_MIN;
  int sec = (hms % SEC_PER_HOUR) % SEC_PER_MIN; // or hms % SEC_PER_MIN

  printf("Current local time: %d:%02d:%02d\n", hour, min, sec);
  return 0;
}