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
#include <map>

int main() {
  int n;
  cin >> n;
  
  std::vector<int> m(n);
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
  }
  
  // value -> index map
  std::map<int, int> index;
  for (int i = 0; i < n; ++i) {
    index[m[i]] = i;
  }
  
  std::vector<std::pair<int, int>> swaps;
  
  for (int i = m.size() - 1; i > 0; --i) {
    for (int j = m[i]; j <= i; ++j) {
      // swap
      int k = index[j + 1];
      int itemp = index[j];
      
      swaps.push_back({itemp, k});
      
      m[index[j]] = m[k];
      index[j] = k;

      index[m[k]] = itemp;
      m[k] = j;
    }
  }
  
  cout << swaps.size() << "\n";
  for (int i = 0; i < swaps.size(); ++i) {
    cout << swaps[i].first + 1 << " " << swaps[i].second + 1 << "\n";
  }
  
  return 0;
}

