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
      for (ull j = 2; j * i < k + 1; ++j) {
        primes[j * i] = false;
      }
    }
  }
  
  ull *divisors = new ull[k + 1];
  divisors[0] = 0;
  divisors[1] = 1;
  
  for (ull i = 2; i < k + 1; ++i) {
    if (primes[i]) {
      divisors[i] = 2;
    }
  }
  
  ull max = 0;
  ull max_index = 0;
  
  for (ull i = 2; i < k + 1; ++i) {
    ull counter = 0;
    
    if (primes[i]) {
      counter = 2;
    } else {
      // min(x, n / x) <= sqrt(n)
      for (ull j = 1; j <= sqrt(i); ++j) {
        if (i % j == 0) {
          if (i / j == j) {
            // perfect square
            ++counter;
          } else {
            counter += 2;
          }
        }
      }
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
