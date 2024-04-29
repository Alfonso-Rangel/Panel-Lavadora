#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
  int min = 1, sec = 10;
  while(1) {
    printf("%d:%02d\n", min, sec);
    if(min == 0 && sec == 0) {
      break;
    }
    if(sec == 0) {
      min--;
      sec = 59;
    } else {
      sec--;
    }
  }
}
