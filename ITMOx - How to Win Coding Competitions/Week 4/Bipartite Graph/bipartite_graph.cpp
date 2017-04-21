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
#include <iterator>
#include <algorithm>

typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vii;

bool odd_cycle = false;
vi color;

void dfs(vii G, int index, int parent) {
  color[index] = 1;
  for (int i = 0; i < G[index].size(); ++i) {
    int adj = G[index][i];
    if (adj != parent) {
      // BTDT: in this order
      if (color[adj] == 0) {
        dfs(G, adj, index);
      }
      
      if (color[adj] == 1) {
        return;
      }
    }
  }
  color[index] = 2;
}

int main() {
  int n, m;
  cin >> n >> m;
  
  // no edges - no cycles
  if (m == 0) {
    cout << "YES\n";
    return 0;
  }
  
  vii G(n);
  color.resize(n, 0);
  int start = -1;
  
  for (int i = 0; i < m; ++i) {
    int s, t;
    cin >> s >> t;
    
    if (start == -1) {
      start = s - 1;
    }
    
    if (s == t) {
      odd_cycle = true;
    }
    
    G[s - 1].push_back(t - 1);
    G[t - 1].push_back(s - 1);
  }
  
  if (odd_cycle) {
    cout << "NO\n";
    return 0;
  }

  dfs(G, start, -1);

  int ones = 0;
  for (int i = 0; i < color.size(); ++i) {
    if (color[i] == 1) {
      ones += color[i];
    }
  }
  
  if (ones % 2 == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  
  return 0;
}

