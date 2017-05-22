#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

typedef struct rect
{
    int id;
    int length;
    int width;
    //对于向量元素是结构体的，可在结构体内部定义比较函数，下面按照id,length,width升序排序。
    bool operator< (const rect &a)  const
    {
        if(id!=a.id)
            return id<a.id;
        else
        {
            if(length!=a.length)
                return length<a.length;
            else
                return width<a.width;
        }
    }

    void print(){
        cout<<id<<endl;
    }
}Rect;

bool Comp(const Rect &a,const Rect &b)
{
    return a.id>b.id;
}

void print(vector<Rect> vec){
     for(vector<Rect>::iterator it=vec.begin();it!=vec.end();it++){
         it->print();
    }
}

int main()
{
    vector<Rect> vec;
    Rect rect;
    rect.id=1;
    rect.length=2;
    rect.width=3;
    Rect rect2;
    rect2.id=4;
    rect2.length=5;
    rect2.width=6;

    Rect rect3;
    rect2.id=3;
    rect2.length=4;
    rect2.width=5;

    vec.push_back(rect);
    vec.push_back(rect2);
    vec.push_back(rect3);
    // vector<Rect>::iterator it=vec.begin();
    // cout<<(*it).id<<' '<<(*it).length<<' '<<(*it).width<<endl;    
   
    print(vec);

    reverse(vec.begin(),vec.end());
    print(vec);

    sort(vec.begin(),vec.end(),Comp);
    print(vec);


return 0;

}