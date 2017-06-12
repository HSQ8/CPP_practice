#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
using namespace std;
// uva problem - triangle - 488

int main(){
//  freopen("in.dat", "r", stdin);
  int triangle, amplitude, frequency;
  bool end = false;
  cin >> triangle;
  while(triangle){

    cin >> amplitude >> frequency;
    while(frequency){
      if(end)
        cout << endl;
      end = true;

      for(int j=1;j<amplitude;++j){
        for(int i=1; i<j+1; ++i){
          cout << j;
        }
        cout << endl;
      }

      for(int j=amplitude; j>0;--j){
        for(int i=j; i>0; --i){
          cout << j;
        }
        cout << endl;
      }

      --frequency;
    }

    --triangle;
  }

  return 0;
}
