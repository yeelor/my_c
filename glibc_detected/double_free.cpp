#include <iostream>
using namespace std;
int main() {
  int *a = (int *)malloc(sizeof(int) * 1);

  free(a);
  free(a);

  return 0;
}