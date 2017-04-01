#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

// std::to_string
#include <string>
#include <deque>
#include <iterator>
#include <algorithm>
// std::isnan
#include <cmath>

typedef long long ll;

int main() {
  int n;
  cin >> n;
  
  std::string answer = "";
  std::deque<ll> q;
  ll min;
  bool min_is_set = false;
  
  
  for (int i = 0; i < n; ++i) {
    char operation;
    cin >> operation;
    
    switch (operation) {
      case '+': {
        ll x;
        cin >> x;
        q.push_back(x);
        
        // save the min value
        if (!min_is_set || x < min) {
          min = x;
          min_is_set = true;
        }
        
        break;
      }
      case '-': {
        ll front = q[0];
        q.pop_front();
        
        
        if (front == min) {
          // find the next min value
          if (q.size() > 0) {
            min = *std::min_element(begin(q), end(q));
          } else {
            min_is_set = false;
          }
        }

        break;
      }
      case '?': {
        answer += std::to_string(min) + "\n";
        break;
      }
    }
  }
  
  cout << answer;
  return 0;
}
