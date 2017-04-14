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
#include <vector>
#include <algorithm>

typedef unsigned long long ull;

struct Jewel {
  int index;
  ull v;
  ull w;
  
  friend bool operator<(const Jewel &a, const Jewel &b) {
    return (a.v * 1.0) / a.w > (b.v * 1.0) / b.w;
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  
  std::vector<Jewel> jewels(n);
  
  for (int i = 0; i < n; ++i) {
    Jewel j;
    cin >> j.v >> j.w;
    j.index = i;
    jewels[i] = j;
  }
  
  std::sort(begin(jewels), end(jewels));
  
  for (int i = 0; i < k; ++i) {
    cout << jewels[i].index + 1 << " ";
  }
  cout << "\n";
  
  return 0;
}

