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
  
  std::vector<std::vector<int>> graph(n);
  // 0: white, 1: grey, 2: black
  std::vector<int> color(n, 0);
  
  std::stack<int> v;
  int start = -1;
  bool cycle = false;
  
  for (int i = 0; i < m; ++i) {
    int s, t;
    cin >> s >> t;
    
    if (s == t) {
      // loop
      cycle = true;
      v.push(s - 1);
      v.push(t - 1);
    }
    
    if (start == -1) {
      start = s - 1;
    }
    
    graph[s - 1].push_back(t - 1);
  }
 
  if (!cycle) {
    v.push(start);
    color[start] = 1;
  }
  
  while (!v.empty() && !cycle) {
    int next;
    bool has_next = false;
    
    for (int i = 0; i < graph[v.top()].size(); ++i) {
      next = graph[v.top()][i];
      
      if (color[next] == 1) {
        cycle = true;
        break;
      }
      
      if (color[next] == 0) {
        has_next = true;
        break;
      }
    }

    if (has_next || cycle) {
      // grey
      v.push(next);
      color[next] = 1;
    } else {
      // black
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
