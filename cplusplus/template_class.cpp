#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
class Stack {
 private:
  vector<T> elems;

 public:
  void push(T const&);
  void pop();
  T top() const;
  bool empty() const { return elems.empty(); }
};

template <class T>
void Stack<T>::push(T const& elem) {
  elems.push_back(elem);
}

template <class T>
void Stack<T>::pop() {
  if (elems.empty()) {
    throw out_of_range("Stack::pop(): empty stack");
  }
  elems.pop_back();
}

template <class T>
T Stack<T>::top() const {
  if (elems.empty()) {
    throw out_of_range("Stack::pop(): empty stack");
  }
  return elems.back();
}

int main() {
  try {
    Stack<int> int_stack;
    Stack<string> string_stack;

    int_stack.push(7);
    cout << int_stack.top() << endl;

    string_stack.push("hello world");
    cout << string_stack.top() << endl;
    string_stack.pop();
    string_stack.pop();

  } catch (exception const& ex) {
    cerr << "Exception:" << ex.what() << endl;
    return -1;
  }

  return 0;
}