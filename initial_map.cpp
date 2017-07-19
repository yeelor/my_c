#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  map<string, int> map1;
  map1[string("tttt")] = 1;
  map1[string("ggg")] = 2;
  map1.insert(pair<string, int>("niubi", 3));
  map<string, int>::iterator it = map1.begin();
  while (it != map1.end()) {
    cout << it->first << " " << it->second << endl;
    it++;
  }
  system("pause");
  return 0;
}
