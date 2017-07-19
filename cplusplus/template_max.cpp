#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline T const& Max(T const& a, T const& b) {
  return a < b ? b : a;
}

int main() {
  int i = 39, j = 89;
  float f1 = 12.3, f2 = 32.1;
  string s1 = "hello", s2 = "world";

  cout << Max(i, j) << endl;
  cout << Max(f1, f2) << endl;
  cout << Max(s1,s2) << endl;

  return 0;
}