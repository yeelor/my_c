#include <iostream>
#include <vector>

int main(){
    std::vector<std::string> v1 ;
    // v1.resize(10,"");
    v1.resize(10);
    for( std::vector<std::string>::iterator it = v1.begin(); it!=v1.end();it++){
        std::cout<<*it<<std::endl;
    }
}