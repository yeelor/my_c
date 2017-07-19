#include <iostream>
#include <sstream>
using namespace std;
int main() {
  std::stringstream ss;
  ss<<"\001,"<<",";
  std::cout<<ss.str().length()<<std::endl;

  return 0;
}