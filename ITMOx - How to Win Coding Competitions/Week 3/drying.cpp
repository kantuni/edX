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
#include <cmath>

typedef long long ll;

int main() {
  int n;
  cin >> n;
  
  // max heap init
  std::priority_queue<int> a;
  for (int i = 0; i < n; ++i) {
    ll tmp;
    cin >> tmp;
    a.push(tmp);
  }
  
  ll k;
  cin >> k;
  
  ll minutes = 0;
  
  if (a.size() == 1 && a.top() > k) {
    minutes = ceil((double) a.top() / k);
  } else {
    ll max1 = a.top();
    a.pop();
    ll max2 = a.top();
    
    while (max1 != 0 || max2 != 0) {
      // m = how many minutes max1 was the max
      // max1 - k * x >= max2 - 1 * x
      ll m = ceil((double) (max1 - max2) / (k - 1));
      
      // at least 1 minute max1 was the max
      if (max1 == max2) {
        m = 1;
      }
      
      minutes += m;
      
      // update max1 value, and put it back
      if (max1 - m * k > 0) {
        max1 -= m * k;
      } else {
        max1 = 0;
      }
      a.push(max1);
      
      // new max1
      max1 = a.top();
      if (max1 > minutes) {
        max1 -= minutes;
      } else {
        max1 = 0;
      }
      a.pop();
      
      // new max 2
      max2 = a.top();
      if (max1 > minutes) {
        max2 -= minutes;
      } else {
        max2 = 0;
      }
    }
    
    // print
    while (!a.empty()) {
      cout << a.top() << " ";
      a.pop();
    }
    cout << "\n";
  }
  
  cout << minutes << "\n";
  return 0;
}
