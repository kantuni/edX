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
  int mum = 0;
  
  for (int i = 0; i < n; ++i) {
    std::string cmd;
    cin >> cmd;
    
    if (cmd == "mum!") {
      ++mum;
      if (i != n - 1) {
        continue;
      }
    }
    
    // process mum! commands in batch
    if (mum > 0) {
      if (q.size() % 2 == 0) {
        if (mum % 2 == 1) {
          for (int j = 0; j < q.size() / 2; ++j) {
            q.push_back(q[0]);
            q.pop_front();
          }
        }
      } else {
        int end = mum * (q.size() / 2) % q.size();
        for (int j = 0; j < end; ++j) {
          q.push_back(q[0]);
          q.pop_front();
        }
      }
      
      // reset mum
      mum = 0;
    }
    
    if (cmd == "add") {
      // add the lightsaber
      int x;
      cin >> x;
      q.push_back(x);
      continue;
    }
    
    if (cmd == "take") {
      // take the lightsaber
      q.pop_back();
    }
  }
  
  // print lightsabers
  cout << q.size() << "\n";
  for (int i = 0; i < q.size(); ++i) {
    cout << q[i] << " ";
  }
  cout << "\n";
  
  return 0;
}
