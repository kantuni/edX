#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

int main() {
  int n;
  cin >> n;
  
  bool practice = false, theory = false;
  int max = 0;
  
  int *p = new int[n];
  int *t = new int[n];
  int *diff = new int[n];
  
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  
  for (int i = 0; i < n; ++i) {
    if (p[i] > t[i]) {
      max += p[i];
      practice = true;
    } else {
      max += t[i];
      theory = true;
    }
    
    diff[i] = p[i] - t[i];
  }
  
  if (practice && theory) {
    cout << max << "\n";
  } else if (practice) {
    // find min diff index
    int mdi = 0;
    
    for (int i = 1; i < n; ++i) {
      if (diff[i] < diff[mdi]) {
        mdi = i;
      }
    }
    
    max = max - p[mdi] + t[mdi];
    cout << max << "\n";
  } else {
    // find max diff index
    int mdi = 0;
    
    for (int i = 1; i < n; ++i) {
      if (diff[i] > diff[mdi]) {
        mdi = i;
      }
    }
    
    max = max + p[mdi] - t[mdi];
    cout << max << "\n";
  }
  
  delete [] p;
  delete [] t;
  delete [] diff;
  
  return 0;
}
