#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

// std::to_string
#include <string>
#include <stack>

typedef long long ll;

int main() {
  int n;
  cin >> n;
  
  std::string answer = "";
  
  std::stack<ll> s;
  for (int i = 0; i < n; ++i) {
    char operation;
    cin >> operation;
    
    switch (operation) {
      case '+': {
        ll x;
        cin >> x;
        s.push(x);
        break;
      }
      case '-': {
        answer += std::to_string(s.top()) + "\n";
        s.pop();
        break;
      }
    }
  }
  
  cout << answer;
  return 0;
}
