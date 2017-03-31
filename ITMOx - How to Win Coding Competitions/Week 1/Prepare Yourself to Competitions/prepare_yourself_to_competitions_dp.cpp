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
  
  int *p = new int[n];
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  
  int *t = new int[n];
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  
  int *c = new int[n];
  
  delete[] p;
  delete[] t;
  delete[] c;
  
  return 0;
}
