#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
using namespace std;
// uva problem minesweeper 10189



void display(const vector<int>& _vec, int& _m, int& _n){
  for (int i=0; i<_m; i++){
    for(int j = 0; j<_n; j++){
      if(_vec[i*_n+j]==9)
        cout << "*";
      else cout << _vec[i*_n+j];
    }
    cout << endl;
  }
}


void getNumericField(vector<int>& _vec, int& _m, int& _n){
  for (int i=0; i<_m; i++){
    for(int j = 0; j<_n; j++){
      if(_vec[i*_n+j] == 9){

        if(i<_m-1 and j<_n-1 and _vec[(i+1)*_n+j+1] != 9)
          _vec[(i+1)*_n+j+1]++;

        if( i<_m-1 and _vec[(i+1)*_n+j] != 9)
          _vec[(i+1)*_n+j]++;

        if (i< _m-1 and j> 0  and _vec[(i+1)*_n+j-1] != 9)
          _vec[(i+1)*_n+j-1]++;

        if(i >0 and j<_n-1 and _vec[(i-1)*_n+j+1] != 9)
          _vec[(i-1)*_n+j+1]++;

        if(i>0 and _vec[(i-1)*_n+j] != 9)
          _vec[(i-1)*_n+j]++;

        if(i>0 and j>0 and _vec[(i-1)*_n+j-1] != 9)
          _vec[(i-1)*_n+j-1]++;

        if(j<_n-1 and _vec[i*_n+j+1] != 9)
          _vec[i*_n+j+1]++;

        if(j>0 and _vec[i*_n+j-1] != 9)
          _vec[i*_n+j-1]++;

      }
    }
  }
}

int main(){
 freopen("in.dat", "r", stdin);

  vector<int> field;

  int m,n, count;
  count=1;
  char temp;
  while (cin >> m >> n){
    if (!m and !n)
      break;
    for(int count=0; count < m*n ;count++){
      cin >> temp;
      if(temp == '.')
        field.push_back(0);
      else if (temp == '*')
        field.push_back(9);
    }
    if (count>1)
      cout << endl;
    cout << "Field #" << count << ":"<<endl;
    count ++;
    getNumericField(field,m,n);
    display(field,m,n);
    field.clear();
  }
  return 0;




}
