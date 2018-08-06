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
typedef std::vector<vi> vvi;

// 0: white, 1: red, 2: blue
vvi G;
vi color;

bool DFS(int index, int parent) {
  if (color[parent] == 1 || parent == -1) {
    color[index] = 2;
  } else {
    color[index] = 1;
  }

  for (int i = 0; i < G[index].size(); ++i) {
    int adj = G[index][i];

    if (color[adj] == color[index]) {
      return false;
    }
    
    if (color[adj] == 0) {
      bool barpartite = DFS(adj, index);
      if (!barpartite) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;

  // no edges - no cycles
  if (m == 0) {
    cout << "YES\n";
    return 0;
  }

  G.resize(n);
  color.resize(n, 0);
  bool loop = false;

  for (int i = 0; i < m; ++i) {
    int s, t;
    cin >> s >> t;

    if (s == t) {
      loop = true;
    }

    G[s - 1].push_back(t - 1);
    G[t - 1].push_back(s - 1);
  }

  if (loop) {
    cout << "NO\n";
    return 0;
  }
  
  bool bipartite = true;
  for (int i = 0; i < n; ++i) {
    if (color[i] == 0) {
      bipartite = DFS(i, -1);
      if (!bipartite) {
        break;
      }
    }
  }

  if (bipartite) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}

