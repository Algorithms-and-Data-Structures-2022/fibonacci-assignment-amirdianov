#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }

    return round((pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5));

    //    return 0;
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;

    int prev = fib_prev;
    int now = fib_curr;
    int perem;
    for (int i = 1; i < n + 1; i++) {
      perem = now;
      now = now + prev;
      prev = perem;
    }
    return perem;

    return 0;
  }

  int64_t fib_recursive(int n) {

    if (n <= 1) {
      return n;
    } else {
      return fib_recursive(n - 1) + fib_recursive(n - 2);
    }

    return 0;
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      return cache[n];
    }
    int val = fib_recursive_memoization(n - 1, cache) + fib_recursive_memoization(n - 2, cache);
    cache[n] = val;
    return val;
    // Напишите здесь свой код ...

    return 0;
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }

    // Напишите здесь свой код ...
    return matrix_power(FibMatrix, n)[1][0];
    // Tip: используйте реализованную функцию matrix_pow

    return 0;
  }

}  // namespace assignment
