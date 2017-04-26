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
  long long a, b;
  cin >> a >> b;
  cout << a + b * b << "\n";
  return 0;
}
