#include <exercises/hackerrank/projecteuler/euler003.hpp>

/**
 * @link Problem definition [[docs/hackerrank/projecteuler/euler003.md]]
 */

#include <cmath>
#include <stdexcept>

namespace hackerrank::projecteuler {

long prime_factor(long n) {
  if (n < 2) {
    throw std::invalid_argument("n must be greater than 2");
  }

  long divisor = n;
  long max_prime_factor;
  bool mpf_initialized = false;

  long i = 2;

  while (static_cast<double>(i) <=
         std::sqrt(static_cast<long double>(divisor))) {
    if (0 == divisor % i) {
      divisor = divisor / i;
      max_prime_factor = divisor;
      mpf_initialized = true;
    } else {
      i += 1;
    }
  }

  if (!mpf_initialized) {
    return n;
  }

  return max_prime_factor;
}

long euler003(long n) { return prime_factor(n); }

} // namespace hackerrank::projecteuler
