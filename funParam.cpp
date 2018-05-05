
/**

C++中一个函数作为作为另一个函数的参数：
 把函数名作为参数就是函数的地址了.
要将函数名作为参数，需要使用函数指针。
函数指针的定义格式为
ret_type (*var_name)(arg_list);
表示返回值为ret_type，参数列表为arg_list的函数指针var_name.
如
int (*p)(int,int);
表示返回值为int,参数为两个int型的函数指针p。
以函数指针作为形参，即可实现函数名作为参数，由另一个函数调用。

**/
#include<iostream>  
using namespace std;  
void sort(int a[], int n, int (*cmp)(int,int))  
{   
    /*对数组a排序，排序原则由cmp指定，若cmp为真，表示两元素逆序*/  
    for(int i=0;i<n-1;i++)  
        for(int j=i+1;j<n;j++)  
            if(cmp(a[i],a[j]))  
                swap(a[i],a[j]);  
}  
  
int CmpAsc(int x, int y)  
{  
    //如果x>y返回1，否则返回0；  
    if(x>y)return 1;  
    else return 0;  
}  
  
int CmpDec(int x, int y)  
{  
    //如果x<y返回1，否则返回0；  
    if(x<y)return 1;  
    else return 0;  
}  
  
int CmpAbsAsc(int x, int y)  
{//如果abs(x)>abs(y)返回1，否则返回0  
    if(abs(x)>abs(y))return 1;  
    else return 0;  
}  
int main(void)  
{  
    int a[10],i,n;   
    int slt;  
    /*读入n和n个整数，存入数组a*/  
    cin>>n;  
    for(int i=0;i<n;i++)  
        cin>>a[i];  
    /*读入用户的选择，存入slt; */  
  
    cin>>slt;  
    switch(slt)  
    {  
    case 1:   sort(a, n, CmpAsc); break;  
    case 2:   sort(a, n, CmpDec); break;  
    case 3:   sort(a, n, CmpAbsAsc);break;  
    }  
    /*输出排序后的数组*/  
    for(int i=0;i<n;i++)  
    {  
        if(i==0)  
            cout<<a[i];  
        else  
            cout<<" "<<a[i];  
    }  
    cout<<endl;  
    return 0;  
}  

