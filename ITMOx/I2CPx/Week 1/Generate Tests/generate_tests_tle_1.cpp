#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <iterator>
#include <algorithm>
#include <cmath>

typedef unsigned long long ull;

ull number_of_divisors(ull n) {
  ull counter = 0;
  // min(x, n / x) <= sqrt(n)
  for (ull i = 1; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      if (n / i == i) {
        // perfect square
        ++counter;
      } else {
        counter += 2;
      }
    }
  }
  return counter;
}

int main() {
  ull k;
  cin >> k;
  
  bool *primes = new bool[k + 1];
  std::fill_n(primes, k + 1, true);
  primes[0] = false;
  primes[1] = false;
  
  // sieve of Eratosthenes
  for (ull i = 2; i < sqrt(k + 1); ++i) {
    if (primes[i]) {
      // j = i^2, i^2 + i, i^2 + 2i, ...
      for (ull j = 0; i * i + j * i < k + 1; ++j) {
        primes[i * i + j * i] = false;
      }
    }
  }
  
  ull *divisors = new ull[k + 1];
  std::fill_n(divisors, k + 1, 2);
  divisors[0] = 0;
  divisors[1] = 1;
  
  ull max = 0, max_index = 0;
  for (ull i = 2; i < k + 1; ++i) {
    ull counter;
    if (primes[i]) {
      counter = 2;
    } else {
      counter = number_of_divisors(i);
    }
    
    if (max < counter) {
      max = counter;
      max_index = i;
    }
    divisors[i] = counter;
  }
  
  cout << k - max_index + 1 << "\n";
  return 0;
}
