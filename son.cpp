#include <iostream>
using namespace std;

class GrandFather  
{  
public:  
    GrandFather() {}  
    virtual void fun()  
    {  
        cout << "GrandFather call function!" << endl;  
    }  
};  
  
class Father : public GrandFather  
{  
public:  
     Father() {}  
     void fun()  
     {  
         cout << "Father call function!" << endl;  
     }  
};  
  
  
class Son : public Father  
{  
public:  
    Son() {}  
    void fun()  
    {  
        cout << "Son call function!" << endl;  
    }  
};  
  
void print(GrandFather* father)  
{  
    father->fun();  
}  
  
int main(int argc, char* argv[])  
{  
    Father * pfather = new Son;  
    pfather->fun();  
    GrandFather * pgfather = new Father;  
    print(pgfather);
    return 0;  
}