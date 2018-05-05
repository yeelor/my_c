#include <iostream>
#include <math.h>

using namespace std;

void printT(){
  std::cout << "pring test";
}

int main() {
//   int i;
//   float f = 166.71;
//   i = static_cast<int>(f);
//   cout << i << endl;

  cout <<sqrt(1.44)<<endl;
  cout <<sqrt(0)<<endl;

  int i;
  string p = "This is an example.";
  string please = " please ";
  
  // i = reinterpret_cast<int>(&p);
  cout <<"i:"<<i << endl;
  cout <<"p:"<< p << endl;
  cout <<"p + please:"<< p +please << endl;


  cout <<"sizeof(int):"<<sizeof(int)<<endl;
  cout <<"sizeof(long):"<<sizeof(long)<<endl;
  cout <<"sizeof(i):"<<sizeof(i)<<endl;
  cout <<"sizeof(p):"<<sizeof(p)<<endl;

  string s = "guotao";
  cout << "sizeof('guotao'):"<<sizeof(s)<<endl;
  cout << "sizeof(s):"<<sizeof(s)<<endl;
  cout <<"s.size():"<<s.size()<<endl;

	cout << "The value of INT_MAX is "<< std::numeric_limits<int>::max()<<endl;	
  cout << "The value of INT_MIN is "<< std::numeric_limits<int>::min()<<endl;	

  return 0;
}