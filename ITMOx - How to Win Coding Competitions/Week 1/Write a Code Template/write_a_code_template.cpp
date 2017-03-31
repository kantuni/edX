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
#include <algorithm>

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
    templates[i].first = language;
    
    std::string code = "";
    while (true) {
      std::string line;
      cin >> line;
      
      if (line == "%TEMPLATE-START%") {
        continue;
      }
      
      if (line == "%TEMPLATE-END%") {
        break;
      }
      
      code += line;
    }
    templates[i].second = code;
  }
  
  std::string optimal = templates[0].first;
  int min = INT_MAX;
  
  for (auto t : templates) {
    int total = 0;
    
    for (int i = 0; i < t.second.length() - 1; ++i) {
      int xa = keyboard[t.second[i]].first;
      int xb = keyboard[t.second[i + 1]].first;
      int ya = keyboard[t.second[i]].second;
      int yb = keyboard[t.second[i + 1]].second;
      total += std::max(abs(xa - xb), abs(ya - yb));
    }
    
    if (total < min) {
      min = total;
      optimal = t.first;
    }
  }
  
  cout << optimal << "\n";
  cout << min << "\n";
  
  return 0;
}
