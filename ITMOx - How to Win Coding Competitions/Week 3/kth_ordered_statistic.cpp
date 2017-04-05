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
  ll n, k1, k2;
  cin >> n >> k1 >> k2;
  
  ll *a = new ll[n];
  ll A, B, C;
  cin >> A >> B >> C >> a[0] >> a[1];
  
  for (int i = 2; i < n; ++i) {
    a[i] = A * a[i - 2] + B * a[i - 1] + C;
  }
  
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
  
  return 0;
}
