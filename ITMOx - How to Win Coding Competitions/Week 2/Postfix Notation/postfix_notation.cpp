#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <stack>

int main() {
  int n;
  cin >> n;
  
  std::stack<int> s;
  for (int i = 0; i < n; ++i) {
    char x;
    cin >> x;
    
    switch (x) {
      case '+': {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        s.push(a + b);
        break;
      }
      case '-': {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        s.push(b - a);
        break;
      }
      case '*': {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        s.push(a * b);
        break;
      }
      default: {
        s.push(x - '0');
      }
    }
  }
  
  cout << s.top() << "\n";
  return 0;
}
