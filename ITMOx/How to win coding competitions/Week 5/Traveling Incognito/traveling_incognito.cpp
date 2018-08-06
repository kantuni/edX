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
#include <queue>

typedef unsigned long long ull;
typedef std::vector<std::pair<ull, ull>> vii;
typedef std::vector<vii> vvii;

std::vector<ull> dist;

struct Edge {
  ull source, target, weight;
  
  Edge(ull s, ull t, ull w) {
    this->source = s;
    this->target = t;
    this->weight = w;
  }
  
  // invert operator trick
  friend bool operator<(const Edge& a, const Edge& b) {
    return dist[a.source] + a.weight > dist[b.source] + b.weight;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  
  ull s, t;
  cin >> s >> t;
  --s;
  --t;
  
  vvii G(n);
  for (int i = 0; i < m; ++i) {
    ull s, t, w;
    cin >> s >> t >> w;
    
    G[s - 1].push_back({t - 1, w});
    G[t - 1].push_back({s - 1, w});
  }
  
  ull a, b;
  cin >> a >> b;
  
  // remove edges with weights > a and < b
  for (int i = 0; i < G.size(); ++i) {
    for (int j = 0; j < G[i].size(); ++j) {
      if (G[i][j].second > a && G[i][j].second < b) {
        G[i].erase(begin(G[i]) + j);
      }
    }
  }
  
  std::vector<int> color(n, 0);
  dist.resize(n, 10000000000);
  dist[s] = 0;
  
  std::priority_queue<Edge> q;
  Edge start(s, s, 0);
  q.push(start);
  
  while (!q.empty()) {
    Edge min = q.top();
    q.pop();
    
    if (color[min.target] == 1) {
      continue;
    }
    
    if (dist[min.source] + min.weight < dist[min.target]) {
      dist[min.target] = dist[min.source] + min.weight;
    }
    
    for (int i = 0; i < G[min.target].size(); ++i) {
      if (color[G[min.target][i].first] != 1) {
        Edge adj(min.target, G[min.target][i].first, G[min.target][i].second);
        q.push(adj);
      }
    }
    color[min.target] = 1;
  }
  
  if (color[t] == 1) {
    cout << dist[t] << "\n";
  } else {
    cout << -1 << "\n";
  }

  return 0;
}
