#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <list>
#include <iterator>
#include <algorithm>

typedef long long ll;

int main() {
  int n;
  cin >> n;
  
  std::list<ll> a;
  for (int i = 0; i < n; ++i) {
    ll tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  
  ll k;
  cin >> k;
  
  a.sort();
  
  ll minutes = 0;
  while (a.back() != 0) {
    // radiator
    if (a.back() > k) {
      a.back() -= k;
    } else {
      a.back() = 0;
    }
    
    std::list<ll>::iterator last = std::prev(end(a));
    std::list<ll>::iterator j = begin(a);
    
    // every minute -1
    for (auto it = begin(a); it != last; ++it) {
      if (*it >= 1) {
        --(*it);
      }

      if (*it <= *last) {
        j = it;
      }
    }
    
    // insert the previous max into the corresponding position
    if (a.size() > 1) {
      ll tmp = a.back();
      a.pop_back();
      a.insert(std::next(j), tmp);
    }
    
    ++minutes;
  }
  
  cout << minutes << "\n";
  return 0;
}
