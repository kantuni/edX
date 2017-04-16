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

typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  
  std::vector<ll> m(n);
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
  }
  
  if (k == 1) {
    cout << "YES\n";
    return 0;
  }
  
  for (int i = 0; i < n - k; ++i) {
    std::vector<ll> s;
    for (int j = i; j < n; j += k) {
      s.push_back(m[j]);
    }
    std::sort(begin(s), end(s));
    
    int l = 0;
    for (int j = i; j < n; j += k) {
      m[j] = s[l];
      ++l;
    }
  }
  
  bool sorted = true;
  for (int i = 0; i < n - 1; ++i) {
    if (m[i] > m[i + 1]) {
      sorted = false;
      break;
    }
  }
  
  if (sorted) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  
  return 0;
}

