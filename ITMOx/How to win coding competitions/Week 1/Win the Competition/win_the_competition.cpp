#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <vector>
#include <iterator>
#include <algorithm>

int main() {
  int n;
  cin >> n;
  
  std::vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  
  std::sort(begin(t), end(t));
  
  int time = 300 * 60;
  int max = 0;
  
  int i = 0;
  while (time - t[i] >= 0 && i < n) {
    time -= t[i];
    ++max;
    ++i;
  }
  
  cout << max << "\n";
  return 0;
}
