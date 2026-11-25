#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

typedef float (*pi_func)(int);
typedef float (*e_func)(int);

int main(void) {
  void *lib = NULL;
  pi_func pi = NULL;
  e_func e = NULL;
  const char *libs[] = {"./lib1/libimplement.so", "./lib2/libimplement.so"};
  int curr_lib = 0;
  int command = 0;
  int arg = 0;
  lib = dlopen(libs[curr_lib], RTLD_LAZY);
  if (lib == NULL) {
    fprintf(stderr, "lib load error: %s\n", dlerror());
    return 1;
  }
  pi = (pi_func)dlsym(lib, "pi");
  e = (e_func)dlsym(lib, "e");
  if (pi == NULL || e == NULL) {
    fprintf(stderr, "func load error: %s\n", dlerror());
    dlclose(lib);
    return 1;
  }
  while (1) {
    printf("\ncurr. lib: %d\n", curr_lib + 1);
    printf("enter command: ");
    // Считываем команду пользователя
    if (scanf("%d", &command) != 1) {
      printf("input error\n");
      break;
    }
    // Выход из программы
    if (command == -1) {
      break;
    }
    // Переключение библиотеки
    if (command == 0) {
      dlclose(lib);
      curr_lib = 1 - curr_lib;
      lib = dlopen(libs[curr_lib], RTLD_LAZY);
      if (lib == NULL) {
        fprintf(stderr, "lib load error: %s\n", dlerror());
        return 1;
      }
      pi = (pi_func)dlsym(lib, "pi");
      e = (e_func)dlsym(lib, "e");
      if (pi == NULL || e == NULL) {
        fprintf(stderr, "func load error: %s\n", dlerror());
        dlclose(lib);
        return 1;
      }
      continue;
    }
    // Проверка команды
    if (command != 1 && command != 2) {
      printf("input error\n");
      continue;
    }
    // Считываем аргумент функции
    printf("enter argument: ");
    if (scanf("%d", &arg) != 1) {
      printf("input error\n");
      break;
    }
    // Вычисление числа pi или e
    if (command == 1) {
      printf("pi(%d) = %f\n", arg, pi(arg));
    } else {
      printf("e(%d) = %f\n", arg, e(arg));
    }
  }
  dlclose(lib);
  return 0;
}