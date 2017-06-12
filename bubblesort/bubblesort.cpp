#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;
void sort (vector<int>& _arr){
  for (int j=0;j < _arr.size();j++){

    for (int i=0;i < _arr.size()-1-j;i++){
      int temp;
      if (_arr[i]>_arr[i+1]){
        temp = _arr[i+1];
        _arr[i+1]=_arr[i];
        _arr[i]=temp;
      }
    }
  }
}

int main(){
  vector<int> arr = {1,2,3,41,64,27,1,7,81,4,7,1,1,4,7,54,74,8,56,8,2,5,5,7,24,88,4,1,4,7,5,1,5,3};

  cout << "before sort \n";

  for (int i=0;i < arr.size();i++)
    cout << arr[i] << " ";
  cout <<endl;

  sort(arr);

  cout << "after sort \n";
  for (int i=0;i < arr.size();i++)
    cout << arr[i] << " ";
  cout <<endl;

  return 0;
}
