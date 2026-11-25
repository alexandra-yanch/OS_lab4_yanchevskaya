#include "../include/contracts.h"

float pi(int k) {
  if (k == 0) {
    return -1.0f;
  }
  double res = 2.0; // начальное значение произведения
  for (int n = 1; n < k; n++) {
    double num = 4.0 * n * n;
    double denom = num - 1.0;
    res *= num / denom;
  }
  return (float)res;
}

float e(int x) {
  if (x < 0) {
    return -1.0f;
  }
  double sum = 1.0;
  double term = 1.0;
  for (int n = 1; n <= x; n++) {
    term /= n;
    sum += term;
  }
  return (float)sum;
}