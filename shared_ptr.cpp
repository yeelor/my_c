#include <cassert>
#include <tr1/memory>
using namespace std;


class A {
    std::tr1::shared_ptr<int> no_;
public:
    A(std::tr1::shared_ptr<int> no) : no_(no) {}
    void value(int i) {
        *no_=i;
    }
};
class B {
    std::tr1::shared_ptr<int> no_;
public:
    B(std::tr1::shared_ptr<int> no) : no_(no) {}
    int value() const {
        return *no_;
    }
};
int main() {
    std::tr1::shared_ptr<int> temp(new int(14));
    A a(temp);
    B b(temp);
    a.value(28);
    assert(b.value()==28);
} 
