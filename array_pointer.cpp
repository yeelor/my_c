#include <iostream>
using namespace std;

// http://www.cnblogs.com/mq0036/p/3382732.html

int main() {
  int a[3][4] = {{1, 2, 3, 4}};
  int(*b)
      [4];  //数组指针（也称行指针）,也就是说执行b+1时，b要跨过n个整型数据的长度。

  b = a;
  // b++;       //该语句执行过后，也就是b=b+1;p跨过行a[0][]指向了行a[1][]

  int *p[3];
  // p++; //该语句表示p数组指向下一个数组元素。注：此数组每一个元素都是一个指针
  for (int i = 0; i < 3; i++) {
    p[i] = a[i];
    // std::cout << a[i] << std::endl;
  }

/**
同时用来指向二维数组时，其引用和用数组名引用都是一样的。
*(p[i]+j)、*(*(p+i)+j)、(*(p+i))[j]、p[i][j]
**/
  std::cout << p[0][2] <<'\t'<< b[0][2] << std::endl;
  std::cout << *(p[0] + 2)<<'\t' << *(b[0] + 2) << std::endl;
  std::cout << *(*(p+0)+2)<<'\t' << *(*(b+0)+2) << std::endl;
  std::cout << (*(p+0))[2]<<'\t' << (*(b+0))[2] << std::endl;
  return 0;
}