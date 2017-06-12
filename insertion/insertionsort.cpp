#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

void sort (vector<int>& _arr){
  for (int j=1; j < _arr.size() ; j++){
    int i=j;
    while (_arr[i] > _arr[i+1]){
      int temp = _arr[i];
      _arr[i] = _arr[i+1];
      _arr[i+1] = temp;
      i--;
    }
  }
}

void sortwithiterator (vector<int>& _arr){
  vector<int>::iterator it=_arr.begin();
  for (it++; it != _arr.end();it++){
    vector<int>::iterator itt=it;
    while (*itt > *(itt+1)){
      int temp = *itt;
      *itt = *(itt+1);
      *(itt+1) = temp;
      itt--;
    }
  }
}

int main(){
  vector<int> arr = {1,2,3,41,64,27,1,7,81,4,7,1,1,4,7,54,74,8,56,8,2,5,5,7,24,88,4,1,4,7,5,1,5,3};

  cout << "before sort \n";

  for (int i=0;i < arr.size();i++)
    cout << arr[i] << " ";
  cout <<endl;

//  sort(arr);

  cout << "after sort \n";
  for (int i=0;i < arr.size();i++)
    cout << arr[i] << " ";
  cout << endl;

  sortwithiterator(arr);

  cout << "after sort with iterator \n";
  for (int i=0;i < arr.size();i++)
    cout << arr[i] << " ";
  cout <<endl;
  return 0;
}
