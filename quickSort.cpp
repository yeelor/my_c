#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      cout<<"i="<<i<<",j="<<j<<endl;
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

int main(){
    int arr[] ={19,21,3,11,334,8};
    quickSort(arr,0,5);
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        cout<<arr[i]<<endl;
    }

}