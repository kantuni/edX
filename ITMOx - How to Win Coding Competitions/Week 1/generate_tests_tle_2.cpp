#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

typedef unsigned long long ull;

int main() {
  ull k;
  cin >> k;
  
  ull *number_of_divisors = new ull[k + 1];
  std::fill_n(number_of_divisors, k + 1, 1);
  number_of_divisors[0] = 0;
  number_of_divisors[1] = 1;
  
  for (ull i = 2; i < k + 1; ++i) {
    for (ull j = i; j < k + 1; j += i) {
      ++number_of_divisors[j];
    }
  }
  
  ull max = 0;
  ull max_index = 0;
  
  for (ull i = 0; i < k + 1; ++i) {
    if (number_of_divisors[i] > max) {
      max = number_of_divisors[i];
      max_index = i;
      cout << max_index << " ";
    }
  }
  cout << "\n";
  
  cout << k - max_index + 1 << "\n";
  return 0;
}
