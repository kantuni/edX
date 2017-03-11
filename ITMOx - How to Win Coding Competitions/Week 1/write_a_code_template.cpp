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
#include <unordered_map>

int main() {
  int w, h;
  cin >> w >> h;
  
  std::unordered_map<char, std::pair<int, int>> keyboard;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      char symbol;
      cin >> symbol;
      keyboard[symbol] = {j, i};
    }
  }
  
  std::pair<std::string, std::string> templates[3];
  
  for (int i = 0; i < 3; ++i) {
    std::string language;
    cin >> language;
    templates[0].first = language;
    
    std::string code = "";
    while (true) {
      std::string line;
      cin >> line;
      
      if (line == "%TEMPLATE-END%") {
        break;
      }
      
      code += line;
    }
    templates[0].second = code;
  }
  
  cout << "\n\n\n";
  cout << templates[0].second << "\n";
  
  return 0;
}
