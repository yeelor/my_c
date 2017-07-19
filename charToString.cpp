#include<stdio.h>
#include<stdlib.h>
#include<string>
#include <iostream>


int main(){
    // char* c  = {'a','b','c'};

    char c[] = "hello";//直接赋值

    std::string s(c);
    std::cout<<s.size() <<std::endl;

    return 0;
}