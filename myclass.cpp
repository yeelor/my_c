#include <iostream>
using namespace std;
class myClass
{
  public:
    myClass();  // 构造函数，无返回类型，可以有参数列表，这里省去
    ~myClass(); // 析构函数
    int a;
    const int b;
    void print()
    {
        cout << a << endl;
        cout << b << endl;
    }
};

// myClass::myClass() : a(1), b(1) // 初始化列表
myClass::myClass() : b(1), a(b) // 初始化列表
{
}

int main()
{
    myClass *mc = new myClass;
    mc->print();
    return 0;
}