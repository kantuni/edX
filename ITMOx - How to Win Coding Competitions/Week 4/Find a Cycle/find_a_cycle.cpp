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
#include <stack>

int main() {
  int n, m;
  cin >> n >> m;
  
  // no edges - no cycles
  if (m == 0) {
    cout << "NO\n";
    return 0;
  }
  
  std::vector<std::vector<int>> G(n);
  std::vector<int> color(n, 0);
  
  std::stack<int> v;
  bool cycle = false;
  int start = -1;
  
  for (int i = 0; i < m; ++i) {
    int s, t;
    cin >> s >> t;
    
    if (start == -1) {
      start = s - 1;
    }
    
    if (s == t) {
      // loop
      cycle = true;
      v.push(s - 1);
      v.push(t - 1);
    }
    
    G[s - 1].push_back(t - 1);
  }
 
  if (!cycle) {
    v.push(start);
    color[start] = 1;
  }
  
  while (!v.empty() && !cycle) {
    bool has_adj = false;
    int adj;
    
    for (int i = 0; i < G[v.top()].size(); ++i) {
      adj = G[v.top()][i];
      
      if (color[adj] == 1) {
        cycle = true;
        break;
      }
      
      if (color[adj] == 0) {
        has_adj = true;
        break;
      }
    }

    if (has_adj || cycle) {
      v.push(adj);
      color[adj] = 1;
    } else {
      color[v.top()] = 2;
      v.pop();
    }
  }
  
  if (cycle) {
    cout << "YES\n";
    
    // print the cycle
    std::stack<int> c;
    int source = v.top();
    v.pop();
    while (v.top() != source) {
      c.push(v.top());
      v.pop();
    }
    c.push(source);
    
    while (!c.empty()) {
      cout << c.top() + 1 << " ";
      c.pop();
    }
    cout << "\n";
  } else {
    cout << "NO\n";
  }
  
  return 0;  
}

