#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <string>
#include <stack>

int main() {
  int n;
  cin >> n;
  
  std::string answer = "";
  
  for (int i = 0; i < n; ++i) {
    std::string line;
    cin >> line;
    
    bool valid = true;
    std::stack<char> s;

    for (int j = 0; j < line.length(); ++j) {
      switch (line[j]) {
        case '(': {
          s.push('(');
          break;
        }
        case ')': {
          if (!s.empty() && s.top() == '(') {
            s.pop();
          } else {
            valid = false;
          }
          break;
        }
        case '[': {
          s.push('[');
          break;
        }
        case ']': {
          if (!s.empty() && s.top() == '[') {
            s.pop();
          } else {
            valid = false;
          }
          break;
        }
      }
    }

    if (valid && s.empty()) {
      answer += "YES\n";
    } else {
      answer += "NO\n";
    }   
  }
  
  cout << answer;
  return 0;
}
