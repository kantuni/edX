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

typedef std::vector<std::pair<int, int>> vii;
typedef std::vector<vii> vvii;

std::vector<int> dist;

struct Edge {
  int source;
  int target;
  int weight;
  
  Edge(int s, int t, int w) {
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
  
  vvii G(n);
  for (int i = 0; i < m; ++i) {
    int s, t, w;
    cin >> s >> t >> w;
    G[s - 1].push_back({t - 1, w});
    G[t - 1].push_back({s - 1, w});
  }
  
  std::vector<int> color(n, 0);
  dist.resize(n, 1000000);
  dist[0] = 0;
  
  std::priority_queue<Edge> q;
  Edge start(0, 0, 0);
  q.push(start);
  
  while (!q.empty()) {
    Edge min = q.top();
    q.pop();
    
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
  
  for (int i = 0; i < n; ++i) {
    cout << dist[i] << " ";
  }
  cout << "\n";

  return 0;
}

