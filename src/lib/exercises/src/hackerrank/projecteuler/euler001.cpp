#include <exercises/hackerrank/projecteuler/euler001.hpp>

/**
 * @link Problem definition [[docs/hackerrank/projecteuler/euler001.md]]
 */

#include <algorithm>

namespace hackerrank::projecteuler {

unsigned long min(unsigned long a, unsigned long b) {
  if (a > b) {
    return b;
  }

  return a;
}

// Function to return gcd of a and b
unsigned long gcd(unsigned long a, unsigned long b) {
  // Find Minimum of a and b
  unsigned long result = min(a, b);
  while (result > 0) {
    if (a % result == 0 && b % result == 0) {
      break;
    }
    result--;
  }

  // Return gcd of a and b
  return result;
}

// Function to find sum of Arithmetic Progression series
unsigned long sum_of_arithmetic_progression(unsigned long n, unsigned long d) {
  // Number of terms
  n = n / d;
  return n * (1 + n) * d / 2;
}

// Function to find the sum of all multiples of a and b below n
unsigned long euler001(int a, int b, int n) {
  // Since, we need the sum of multiples less than N
  n = n - 1;

  unsigned long lcm = (a * b) / gcd(a, b);

  return sum_of_arithmetic_progression(n, a) +
         sum_of_arithmetic_progression(n, b) -
         sum_of_arithmetic_progression(n, lcm);
}

} // namespace hackerrank::projecteuler
