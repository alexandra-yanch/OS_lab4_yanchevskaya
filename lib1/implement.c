#include "../include/contracts.h"
#include <math.h>

float pi(int k) {
  double sum = 0.0; // хранит сумму ряда
  int sign = 1;     // определяет знак текущего слагаемого

  for (int n = 0; n < k; n++) {
    sum += (double)sign / (2 * n + 1); // формирует нечетные знаменатели
    sign *= -1;                        // знак меняется после каждого шага
  }
  return (float)(4.0 * sum);
}

float e(int x) {
  if (x < 0) {
    return -1.0f; // условное обозначение некорректного аргумента
  }
  double base = 1.0 + 1.0 / x;
  return (float)pow(base, x);
}