#include "../include/contracts.h"
#include <stdio.h>

int main(void) {
  int command;
  int arg;
  while (1) {
    printf("enter command: ");
    if (scanf("%d", &command) != 1) {
      printf("input error\n");
      break;
    }
    if (command == 0) {
      break;
    }
    if (command != 1 && command != 2) {
      printf("input error\n");
      continue;
    }
    printf("enter argument: ");
    if (scanf("%d", &arg) != 1) {
      printf("input error\n");
      break;
    }
    if (command == 1) {
      printf("pi(%d) = %f\n", arg, pi(arg));
    } else {
      printf("e(%d) = %f\n", arg, e(arg));
    }
  }
  return 0;
}