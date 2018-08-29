#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
  int t[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> t[i][j];
    }
  }
  double ans = 0;
  for (int i = 0; i < 3; i++) {
    int a = t[i][0];
    for (int j = 0; j < 3; j++) {
      if (j == i) continue;
      int b = t[j][1];
      for (int k = 0; k < 3; k++) {
        if (k == i || k == j) continue;
        int c = t[k][2];
        double e = sqrt(a * a + b * b + c * c);
        ans = max(ans, e);
      }
    }
  }
  cout << setprecision(17) << ans << "\n";
  return 0;
}
