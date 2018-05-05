#include <iostream>
using namespace std;
//http://www.cnblogs.com/colorfulkoala/archive/2012/09/12/2682601.html

int main() {
  int *a = (int*)malloc(sizeof(int)*1);//16
  int *b = a;
  int *c = (int*)malloc(sizeof(int)*1);

  std::cout<<"a="<<a<<std::endl;
  std::cout<<"b="<<b<<std::endl;
  std::cout<<"c="<<c<<std::endl;

  c[0] = 9;

  a = (int*)realloc(a,sizeof(int)*4);//如果改为5，则会占到c的内存

  std::cout<<"c[0]="<<c[0]<<std::endl;
  std::cout<<"a[4]="<<a[4]<<std::endl;

  b = (int*)realloc(b,sizeof(int)*5);//b的地址与a不再相同

  std::cout<<"a="<<a<<std::endl;
  std::cout<<"b="<<b<<std::endl;

  b[4] = 10;
  std::cout<<"a[4]="<<a[4]<<std::endl;
  std::cout<<"c[0]="<<c[0]<<std::endl;

//   cout<<"sizeof(int *) * 4 = "<<sizeof(int *) * 4<<endl;
//   int *a = (int *)malloc(sizeof(int *) * 4);

//   a[5] = 1;
//   cout << a<<'\t'<<&a[1]<<'\t'<<&a[5] << endl;

//   int *b = (int *)malloc(sizeof(int *) * 4);

  return 0;
}