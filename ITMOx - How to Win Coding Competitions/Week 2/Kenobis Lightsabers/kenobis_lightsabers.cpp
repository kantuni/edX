#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <string>
#include <deque>

int main() {
  int n;
  cin >> n;
  
  std::deque<int> q;
  for (int i = 0; i < n; ++i) {
    std::string cmd;
    cin >> cmd;
    
    if (cmd == "add") {
      int x;
      cin >> x;
      q.push_back(x);
      continue;
    }
    
    if (cmd == "take") {
      q.pop_back();
      continue;
    }
    
    if (cmd == "mum!") {
      for (int j = 0; j < q.size() / 2; ++j) {
        q.push_back(q[0]);
        q.pop_front();
      }
    }
  }
  
  cout << q.size() << "\n";
  for (int i = 0; i < q.size(); ++i) {
    cout << q[i] << " ";
  }
  cout << "\n";
  
  return 0;
}
