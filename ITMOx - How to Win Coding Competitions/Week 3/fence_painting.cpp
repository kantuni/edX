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
  ull n, k;
  cin >> n >> k;
  ull *a = new ull[n];
  for (ull i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  return 0;
}

