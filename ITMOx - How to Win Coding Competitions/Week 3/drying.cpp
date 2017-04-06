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
  int n;
  cin >> n;
  
  ll *a = new ll[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  ll k;
  cin >> k;
  
  return 0;
}
