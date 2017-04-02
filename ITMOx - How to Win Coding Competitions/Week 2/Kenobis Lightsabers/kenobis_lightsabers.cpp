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
#include <iterator>
#include <list>

int main() {
  int n;
  cin >> n;
  
  std::list<int> l;
  std::list<int>::iterator start;
  int cmum = 0;
  
  for (int i = 0; i < n; ++i) {
    std::string cmd;
    cin >> cmd;
    
    if (cmd == "mum!") {
      ++cmum;
      if (i != n - 1) {
        continue;
      }
    }
    
    // process mum! commands in batch
    if (cmum > 0 && l.size() > 1) {
      if (l.size() % 2 == 0) {
        if (cmum % 2 == 1) {
          int offset = l.size() / 2;
          while (offset > 0) {
            ++start;
            if (start == end(l)) {
              start = begin(l);
            }
            --offset;
          }
        }
      } else {
        int offset = (cmum * (l.size() / 2)) % l.size();
        while (offset > 0) {
          ++start;
          if (start == end(l)) {
            start = begin(l);
          }
          --offset;
        }
      }
    }
    
    // reset mum count
    cmum = 0;
    
    if (cmd == "add") {
      // add the lightsaber
      int x;
      cin >> x;
      if (l.empty()) {
        l.push_front(x);
        start = begin(l);
      } else {
        l.insert(start, x);
      }
      continue;
    }
    
    if (cmd == "take") {
      // take the lightsaber
      if (start == begin(l)) {
        l.pop_back();
      } else {
        l.erase(std::prev(start));
      }
    }
  }
  
  // rearrange and print lightsabers
  cout << l.size() << "\n";
  if (l.size() > 0) {
    for (auto it = start; it != end(l); ++it) {
      cout << *it << " ";
    }
    for (auto it = begin(l); it != start; ++it) {
      cout << *it << " ";
    }
    cout << "\n";
  }
  
  return 0;
}
