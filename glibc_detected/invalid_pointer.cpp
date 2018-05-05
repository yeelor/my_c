#include <iostream>
using namespace std;

//http://www.cnblogs.com/colorfulkoala/archive/2012/09/12/2682601.html

int main() {
  // int *a = (int *)malloc(sizeof(int) * 4);

  // a = (int *)realloc(a + 1, sizeof(int) * 2);

  // free(a + 1);//a+1不是连续地址的头部。

  int *a = (int *)malloc(sizeof(int *) * 1);

  int *b = (int *)malloc(sizeof(int *) * 1);

  cout << a << "," << b << endl;

  a[4] = 1;

  cout << b[0] << endl;  //（其实a[4] 就是b[0] ）

  return 0;

  /**
  你看到输出结果了吗？ab的地址正好差了16，呵呵，这说明什么，
  malloc分配地址是有策略的，为什么不连着分配？因为你之后可能
  realloc，如果realloc增加超过16那么就会全部释放然后拷贝到下一片连续的内存
  **/
}