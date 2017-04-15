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
  for (int i = 0; i < k; ++i) {
    Jewel j;
    cin >> j.v >> j.w;
    j.index = i + 1;
    V += j.v;
    W += j.w;
    best.push(j);
  }
  
  std::vector<Jewel> rest(n);
  for (int i = 0; i < n - k; ++i) {
    Jewel j;
    cin >> j.v >> j.w;
    j.index = k + i + 1;
    rest[i] = j;
  }
  
  for (int i = 0; i < n - k; ++i) {
    Jewel t = best.top();
    ull newV = V - t.v + rest[i].v;
    ull newW = W - t.w + rest[i].w;
    
    if ((double) newV / newW > (double) V / W) {
      best.pop();
      best.push(rest[i]);
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

