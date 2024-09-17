#include <exercises/hackerrank/projecteuler/euler001.hpp>

/**
 * @link Problem definition [[docs/hackerrank/projecteuler/euler001.md]]
 */

#include <algorithm>

namespace hackerrank::projecteuler {

// Function to return gcd of a and b
int gcd(int a, int b) {
  // Find Minimum of a and b
  int result = std::min(a, b);
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
int sum_of_arithmetic_progression(int n, int d) {
  // Number of terms
  n = n / d;
  return n * (1 + n) * d / 2;
}

// Function to find the sum of all multiples of a and b below n
int euler001(int a, int b, int n) {
  // Since, we need the sum of multiples less than N
  n = n - 1;

  int lcm = (a * b) / gcd(a, b);

  return sum_of_arithmetic_progression(n, a) +
         sum_of_arithmetic_progression(n, b) -
         sum_of_arithmetic_progression(n, lcm);
}

} // namespace hackerrank::projecteuler
