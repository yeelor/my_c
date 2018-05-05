#include <iostream>
#include <cmath>
using namespace std;
int main() {
  // const char *p = "abcd";
  // cout << (int *)p << endl;
  // cout << p << endl;
  // cout << *p << endl;
  // cout << &p << endl;
  // cout << (int *)&p << endl;

  // string s ;
  // std::cout<<s.empty()<<std::endl;
  // int a = 0;
  // cout<<std::sqrt(a)<<endl;

  int64_t recordCount = 0;
  while (recordCount++ < 10) {
    std::cout<<recordCount<<std::endl;
  }

  std::cout<<sizeof(int)<<std::endl;
  std::cout<<sizeof(recordCount)<<std::endl;
  std::cout<<sizeof(double)<<std::endl;
  

  return 0;
}