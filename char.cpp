#include <iostream>
using namespace std;
int main()
{

    // char ch [] ={'a','b','c'};
    char ch[3+1];
    ch[0]='a';
    ch[1]='b';
    ch[2]='c';
    ch[3]='\0';
    // ch[ch.length]= '\0';// false
    std:string s = std::string(ch);
    cout<<s<<endl;
    return 0;
}