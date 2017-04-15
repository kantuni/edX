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
    return (double) a.v / a.w > (double) b.v / b.w;
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  
  ull V = 0;
  ull W = 0;
  
  std::priority_queue<Jewel, std::vector<Jewel>> best;
  std::vector<Jewel> jewels(n);
  for (int i = 0; i < n; ++i) {
    Jewel j;
    cin >> j.v >> j.w;
    j.index = i + 1;
    jewels[i] = j;
  }
  
  std::sort(begin(jewels), end(jewels));
  
  for (int i = 0; i < k; ++i) {
    V += jewels[i].v;
    W += jewels[i].w;
    best.push(jewels[i]);
  }
  
  for (int i = k; i < n; ++i) {
    Jewel t = best.top();
    ull newV = V - t.v + jewels[i].v;
    ull newW = W - t.w + jewels[i].w;
    
    if ((double) newV / newW > (double) V / W) {
      best.pop();
      best.push(jewels[i]);
      V = newV;
      W = newW;
    }
  }
  
  while (!best.empty()) {
    cout << best.top().index << " ";
    best.pop();
  }
  cout << "\n";
  
  return 0;
}

