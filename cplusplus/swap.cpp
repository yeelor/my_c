#include <iostream>
using namespace std;
 
void swap_reference(int& x, int& y);
void swap_val(int x,int y);
void swap_pointer(int *x,int *y);
 
int main ()
{
   // 局部变量声明
   int a = 100;
   int b = 200;
 
   cout << "交换前，a 的值：" << a << endl;
   cout << "交换前，b 的值：" << b << endl;
 
   /* 调用函数来交换值 */
   swap_val(a, b);
   cout << "交换后，a 的值：" << a << endl;
   cout << "交换后，b 的值：" << b << endl;

   swap_pointer(&a, &b);
   cout << "交换后，a 的值：" << a << endl;
   cout << "交换后，b 的值：" << b << endl;

   swap_reference(a, b);
   cout << "交换后，a 的值：" << a << endl;
   cout << "交换后，b 的值：" << b << endl;
 
   return 0;
}

void swap_val(int x,int y){
    int temp;
    temp = x;
    x=y;
    y=temp;
}

/**
向函数传递参数的指针调用方法，把参数的地址复制给形式参数。在函数内，该地址用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。
按指针传递值，参数指针被传递给函数，就像传递其他值给函数一样。因此相应地，在下面的函数 swap() 中，您需要声明函数参数为指针类型，该函数用于交换参数所指向的两个整数变量的值。
**/
void swap_pointer(int *x,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/***
向函数传递参数的引用调用方法，把引用的地址复制给形式参数。在函数内，该引用用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。
按引用传递值，参数引用被传递给函数，就像传递其他值给函数一样。因此相应地，在下面的函数 swap() 中，您需要声明函数参数为引用类型，该函数用于交换参数所指向的两个整数变量的值。
**/
void swap_reference(int &x, int &y)
{
   int temp;
   temp = x; /* 保存地址 x 的值 */
   x = y;    /* 把 y 赋值给 x */
   y = temp; /* 把 x 赋值给 y  */
}

