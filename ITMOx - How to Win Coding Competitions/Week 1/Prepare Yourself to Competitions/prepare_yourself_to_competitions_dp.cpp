#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

// std::min, std::max
#include <algorithm>

int main() {
  int n;
  cin >> n;
  
  int *p = new int[n + 1];
  p[0] = 0; // convenience
  for (int i = 1; i < n + 1; ++i) {
    cin >> p[i];
  }
  
  int *t = new int[n + 1];
  t[0] = 0; // convenience
  for (int i = 1; i < n + 1; ++i) {
    cin >> t[i];
  }
  
  int **c = new int*[n + 1];
  for (int i = 0; i < n + 1; ++i) {
    c[i] = new int[n + 1];
  }
  
  // c[day][type]
  // 
  // type 0: neither practice nor theory
  // type 1: only practice
  // type 2: only theory
  // type 3: both practice and theory (heterogeneous)
  
  // type 0 is preselected
  c[0][0] = 0;
  
  // others can't be preselected
  c[0][1] = -1000000;
  c[0][2] = -1000000;
  c[0][3] = -1000000;
  
  // type 0: can't be selected on other days (-inf)
  // type 1: c[i][1] = p[i] + max(c[i-1][1], c[i-1][0])
  // type 2: c[i][2] = t[i] + max(c[i-1][2], c[i-1][0])
  // type 3 is a maximum of:
  // - p[i] + c(i - 1) of theory
  // - t[i] + c(i - 1) of practice
  // - max(p[i], t[i]) + c(i - 1) of both
  for (int i = 1; i < n + 1; ++i) {
    c[i][0] = -1000000;
    c[i][1] = p[i] + std::max(c[i - 1][1], c[i - 1][0]);
    c[i][2] = t[i] + std::max(c[i - 1][2], c[i - 1][0]);
    c[i][3] = std::max({
                p[i] + c[i - 1][2],
                t[i] + c[i - 1][1],
                std::max(p[i], t[i]) + c[i - 1][3]
              });
  }
  
  // maximum
  cout << c[n][3] << "\n";
  
  delete[] p;
  delete[] t;
  delete[] c;
  
  return 0;
}
