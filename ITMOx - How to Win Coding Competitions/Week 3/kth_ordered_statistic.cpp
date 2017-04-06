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
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

typedef std::vector<int> vi;
typedef std::vector<std::list<int>> vli;

vi counting_sort(vi A, int base, int digit) {
  vli buckets(base);

  for (auto item: A) {
    int index = (item / (int) pow(base, digit)) % base;
    buckets[index].push_back(item);
  }

  vi B;
  for (auto bucket: buckets) {
    if (!bucket.empty()) {
      for (auto item: bucket) {
        B.push_back(item);
      }
    }
  }

  return B;
}

vi radix_sort(vi A) {
  int base = 10;
  int min = *min_element(begin(A), end(A));
  int max = *max_element(begin(A), end(A));

  if (min < 0) {
    for (auto &item: A) {
      item += abs(min);
    }
  }

  int digits = 0;
  while (max / base > 0) {
    max /= base;
    ++digits;
  }
  
  // BTDT: <= digits
  for (int i = 0; i <= digits; ++i) {
    // sort by every digit
    A = counting_sort(A, base, i);
  }

  if (min < 0) {
    for (auto &item: A) {
      item -= abs(min);
    }
  }

  return A;
}

int main() {
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  
  vi a(n);
  int A, B, C;
  cin >> A >> B >> C >> a[0] >> a[1];
  
  for (int i = 2; i < n; ++i) {
    a[i] = A * a[i - 2] + B * a[i - 1] + C;
  }
  
  vi sorted = radix_sort(a);
  for (int i = k1 - 1; i < k2; ++i) {
    cout << sorted[i] << " ";
  }
  cout << "\n";
  
  return 0;
}
