#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
using namespace std;
// uva problem simple division 10407;

int gcd(int a, int b){
  return (b==0) ? a : gcd(b, a % b);
}

int gcdList( vector<int>& _arr){
  while (_arr.size() > 1){
    for (int k = 0; k < _arr.size() - 1; ++k){
      _arr[k]=gcd(_arr[k],_arr[k+1]);
    }
    _arr.pop_back();
  }
}
int main(){
  // freopen("in.dat", "r", stdin);
register int read, answer;
  vector<int> list;

  while(cin >> read){
    list.push_back(read);
    if(read == 0){
      list.pop_back();
      //printArr(list);
      if (list.size() == 0)
        break;
      for (int b=0; b < list.size()-1; ++b){
        list[b]=abs(list[b] - list[b+1]);
      }
      list.pop_back();

      //printArr(list);
      gcdList(list);
      answer = list[0];
      cout << answer << endl;
      list.clear();
    }
  }
  return 0;
}
