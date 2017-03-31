#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <iomanip>

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  // the inner triangle is similar to the outer triangle
  double d = a / 2.0 + b / 2.0 + c / 2.0;
  cout << std::fixed << std::setprecision(8);
  cout << d / 3.0 << '\n';
  return 0;
}
