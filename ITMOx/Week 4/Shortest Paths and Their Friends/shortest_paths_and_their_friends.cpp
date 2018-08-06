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

typedef long long ll;
typedef std::vector<std::pair<int, ll>> vil;
typedef std::vector<vil> vvil;

int main() {
  int n, m, s;
  cin >> n >> m >> s;

  vvil G(n);

  for (int i = 0; i < m; ++i) {
    // loop
    int s, t;
    ll w;
    cin >> s >> t >> w;
    
    G[s - 1].push_back({t - 1, w});  
  }
  
  // print the graph
  for (int i = 0; i < G.size(); ++i) {
    cout << i + 1 << ": ";
    for (int j = 0; j < G[i].size(); ++j) {
      printf("(%d, %lld) ", G[i][j].first + 1, G[i][j].second);
    }
    cout << "\n";
  }

  return 0;
}

