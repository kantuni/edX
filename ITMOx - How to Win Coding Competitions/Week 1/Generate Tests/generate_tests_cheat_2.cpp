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

typedef unsigned long long ull;

int main() {
  ull k;
  cin >> k;
  
  std::vector<ull> highly_composite_numbers = {
    1, 2, 4, 6, 12, 24, 36, 48, 60, 
    120, 180, 240, 360, 720, 840, 1260, 
    1680, 2520, 5040, 7560, 10080, 15120, 
    20160, 25200, 27720, 45360, 50400, 55440, 
    83160, 110880, 166320, 221760, 277200, 
    332640, 498960, 554400, 665280, 720720, 
    1081080, 1441440, 2162160, 2882880, 3603600, 
    4324320, 6486480, 7207200, 8648640
  };
  
  
  ull max_index = 0;
  for (ull i = 0; i < highly_composite_numbers.size(); ++i) {
    if (highly_composite_numbers[i] > k) {
      break;
    }
    ++max_index;
  }
  
  cout << k - highly_composite_numbers[max_index - 1] + 1 << "\n";
  return 0;
}
