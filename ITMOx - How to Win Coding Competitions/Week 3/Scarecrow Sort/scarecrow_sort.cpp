#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  
  ll *m = new ll[n];
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
  }
  
  for (int i = 0; i < n - k; ++i) {
    if (m[i] > m[i + k]) {
      ll tmp = m[i];
      m[i] = m[i + k];
      m[i + k] = tmp;
      
      for (int j = i; j > 0; --j) {
        if (m[j] < m[j - 1]) {
          ll tmp = m[j];
          m[j] = m[j - 1];
          m[j - 1] = tmp;
        }
      }
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
  
  delete[] m;
  return 0;
}

