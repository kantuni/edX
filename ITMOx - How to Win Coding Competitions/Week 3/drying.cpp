#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <cmath>
#include <queue>

typedef long long ll;

struct Dress {
  ll water;
  ll skip = 0;
  
  bool operator <(const Dress &other) const {
    return water < other.water;
  }
};

int main() {
  int n;
  cin >> n;
  
  // max heap init
  std::priority_queue<Dress> a;
  for (int i = 0; i < n; ++i) {
    Dress tmp;
    cin >> tmp.water;
    a.push(tmp);
  }
  
  ll k;
  cin >> k;
  
  ll minutes = 0;
  
  if (a.size() == 1) {
    minutes = ceil((double) a.top().water / k);
  } else {
    Dress max1 = a.top();
    a.pop();
    Dress max2 = a.top();
    
    while (max1.water != 0 || max2.water != 0) {
      cout << max1.water << " " << max2.water << "\n";
      
      // m = how many minutes max1 was on the radiator
      // max1 - k * x >= max2 - 1 * x
      ll m = ceil((double)(max1.water - max2.water) / (k - 1));
      
      // at least 1 minute max1 was on the radiator
      if (max1.water == max2.water) {
        m = 1;
      }
      
      minutes += m;
      
      // update max1 value, and put it back
      if (max1.water - m * k > 0) {
        max1.water -= m * k;
      } else {
        max1.water = 0;
      }
      
      max1.skip = minutes;
      a.push(max1);
      
      // new max1
      max1 = a.top();
      if (max1.water > minutes - max1.skip) {
        max1.water -= (minutes - max1.skip);
        max1.skip = minutes;
      } else {
        max1.water = 0;
        max1.skip = minutes;
      }
      a.pop();
      
      // new max 2
      max2 = a.top();
      if (max2.water > minutes - max2.skip) {
        max2.water -= (minutes - max2.skip);
      } else {
        max2.water = 0;
      }
    }
    
    cout << "\nQueue:\n";
    while (!a.empty()) {
      printf("(%lld, %lld) ", a.top().water, a.top().skip);
      a.pop();
    }
    cout << "\n";
  }
  
  cout << minutes << "\n";
  return 0;
}
