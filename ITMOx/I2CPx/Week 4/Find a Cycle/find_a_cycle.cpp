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

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main() {
  int n, m;
  cin >> n >> m;

  // no edges - no cycles
  if (m == 0) {
    cout << "NO\n";
    return 0;
  }

  vvi G(n);
  vi color(n, 0);

  std::stack<int> u;
  bool cycle = false;
  int start = -1;
  int seen = 0;

  for (int i = 0; i < m; ++i) {
    int s, t;
    cin >> s >> t;
    
    if (s == t) {
      // loop
      cycle = true;
      u.push(s - 1);
      u.push(t - 1);
    }

    if (start == -1) {
      start = s - 1;
    }

    G[s - 1].push_back(t - 1);
  }

  if (!cycle) {
    // start DFS
    u.push(start);
    color[start] = 1;
    ++seen;
  }

  // DFS using stack
  while (seen <= n && !cycle) {
    if (u.empty()) {
      bool done = true;
      for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
          done = false;
          u.push(i);
          color[i] = 1;
          ++seen;
          break;
        }
      }
      
      // all vertices have been visited
      if (done) {
        break;
      }
    }
    
    bool has_adj = false;
    int adj;
    
    for (int i = 0; i < G[u.top()].size(); ++i) {
      adj = G[u.top()][i];

      if (color[adj] == 0) {
        has_adj = true;
        break;
      } else if (color[adj] == 1) {
        cycle = true;
        break;
      }
    }

    if (has_adj || cycle) {
      u.push(adj);
      color[adj] = 1;
      ++seen;
    } else {
      color[u.top()] = 2;
      u.pop();
    }
  }

  if (cycle) {
    cout << "YES\n";

    // print the cycle in reverse order
    std::stack<int> c;
    int source = u.top();
    u.pop();
    while (u.top() != source) {
      c.push(u.top());
      u.pop();
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

