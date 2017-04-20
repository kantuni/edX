#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

typedef std::vector<std::pair<int, int>> vii;
typedef std::vector<vii> vvii;

int main() {
  int n, m;
  cin >> n >> m;
  
  vvii G(n);
  for (int i = 0; i < m; ++i) {
    // loop
    int s, t, w;
    cin >> s >> t >> w;
    G[s - 1].push_back({t - 1, w});
    G[t - 1].push_back({s - 1, w});
  }
  
  // print the graph
  for (int i = 0; i < G.size(); ++i) {
    cout << i + 1 << ": ";
    for (int j = 0; j < G[i].size(); ++j) {
      printf("(%d, %d) ", G[i][j].first, G[i][j].second);
    }
    cout << "\n";
  }
  
  return 0;  
}

