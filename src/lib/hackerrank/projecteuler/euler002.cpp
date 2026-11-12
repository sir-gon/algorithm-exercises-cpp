#include <exercises/hackerrank/projecteuler/euler002.hpp>

/**
 * @link Problem definition [[docs/hackerrank/projecteuler/euler002.md]]
 */

#include <algorithm>

namespace hackerrank::projecteuler {

int fibo_even_sum(int n) {
  int fibo1 = 1;
  int fibo2 = 1;
  int total = 0;

  while (fibo1 + fibo2 < n) {
    int fibo = fibo1 + fibo2;
    fibo1 = fibo2;
    fibo2 = fibo;

    if (fibo % 2 == 0) {
      total += fibo;
    }
  }

  return total;
}

int euler002(int n) { return fibo_even_sum(n); }

} // namespace hackerrank::projecteuler
