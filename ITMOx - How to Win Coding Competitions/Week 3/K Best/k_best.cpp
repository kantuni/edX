#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <iterator>
#include <vector>
#include <queue>
#include <algorithm>

typedef unsigned long long ull;

struct Jewel {
  int index;
  ull v;
  ull w;
  
  friend bool operator<(const Jewel &a, const Jewel &b) {
    return (double) a.v / a.w < (double) b.v / b.w;
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  
  ull V = 0;
  ull W = 0;
  
  std::priority_queue<Jewel, std::vector<Jewel>> jewels;
  for (int i = 0; i < n; ++i) {
    Jewel j;
    cin >> j.v >> j.w;
    j.index = i + 1;
    jewels.push(j);
  }
  
  std::vector<Jewel> best;
  while (k > 0) {
    V += jewels.top().v;
    W += jewels.top().w;
    best.push_back(jewels.top());
    jewels.pop();
    --k;
    
    std::vector<Jewel> tmp;
    while (!jewels.empty()) {
      tmp.push_back(jewels.top());
      jewels.pop();
    }
    
    for (int i = 0; i < tmp.size(); ++i) {
      tmp[i].v += V;
      tmp[i].w += W;
      jewels.push(tmp[i]);
    }
  }

  for (int i = 0; i < best.size(); ++i) {
    cout << best[i].index << " ";
  }
  cout << "\n";

  return 0;
}

