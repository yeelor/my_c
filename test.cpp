#include <iostream>
using namespace std;

void printT(){
  std::cout << "pring test";
}

int main() {
//   int i;
//   float f = 166.71;
//   i = static_cast<int>(f);
//   cout << i << endl;

  int i;
  std:string p = "This is an example.";
  // i = reinterpret_cast<int>(&p);
  cout <<"i:"<<i << endl;
  cout <<"p:"<< p << endl;

  cout <<"sizeof(int):"<<sizeof(int)<<endl;
  cout <<"sizeof(long):"<<sizeof(long)<<endl;
  cout <<"sizeof(i):"<<sizeof(i)<<endl;
  cout <<"sizeof(p):"<<sizeof(p)<<endl;

  string s = "guotao";
  cout << "sizeof('guotao'):"<<sizeof(s)<<endl;
  cout << "sizeof(s):"<<sizeof(s)<<endl;
  cout <<"s.size():"<<s.size()<<endl;

  return 0;
}