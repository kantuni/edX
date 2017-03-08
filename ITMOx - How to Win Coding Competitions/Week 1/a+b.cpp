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
  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
  
  return 0;
}
