#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

// std::greater
#include <functional>
#include <vector>
#include <queue>

int main() {
  int n;
  cin >> n;
  
  // min heap init
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  int max = 1;
  
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    
    if (i == 0 || a != 0) {
      // add another stack
      min_heap.push(1);
    } else {
      // find the min stack
      int min = min_heap.top();
      min_heap.pop();
      min_heap.push(++min);
      
      // number of cups in the biggest stack
      if (min > max) {
        max = min;
      }
    }
  }
  
  cout << max << "\n";
  return 0;
}
