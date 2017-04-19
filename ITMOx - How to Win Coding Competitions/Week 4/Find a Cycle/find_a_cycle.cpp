#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <vector>

int main() {
  int n, m;
  cin >> n >> m;
  
  std::vector<std::vector<int>> graph(n);
  bool loop = false;
  for (int i = 0; i < m; ++i) {
    int s, t;
    cin >> s >> t;
    
    if (s == t) {
      loop = true;
    }
    
    graph[s - 1].push_back(t - 1);
    graph[t - 1].push_back(s - 1);
  }
  
  if (loop) {
    cout << "YES\n";
    return 0;
  }
  
  for (int i = 0; i < graph.size(); ++i) {
    cout << i + 1 << ": ";
    for (int j = 0; j < graph[i].size(); ++j) {
      cout << graph[i][j] + 1 << " ";
    }
    cout << "\n";
  }
  
  return 0;  
}

