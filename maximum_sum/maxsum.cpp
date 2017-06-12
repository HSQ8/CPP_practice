#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
using namespace std;
// uva problem maximum sum - 108

void print(const vector<int>& _arr)
{for(int i=0; i< _arr.size(); i++) cout << _arr[i] << " ";}


int sum( const int& _horzleft,
    const int& _horzright,
    const int& _verttop,
    const int& _vertdown,
    const vector<int>& _arr,
    const int _size){
  int sum = _arr[_horzleft * _size + _verttop];
  int subtract = sum;
  for (int i = _horzleft ;i < _horzright + 1; i++){
    for (int j = _verttop ; j < _vertdown + 1; j++)
      sum += _arr[i * _size + j];
  }
  if (sum != subtract)
    return sum - subtract;
  else
    return subtract;
}

int main(){
  freopen("in.dat", "r", stdin);
  int temp, col, dimension,verttop, vertdown, horzleft, horzright, maxsum;

  vector<int> square;
  //vector<int> tempvector;

  while (cin >> dimension){
    square.clear();
    col = 0;
    /*
       for(int i=0; i < dimension; i++){
       square.push_back(tempvector);
       cout << "pushback" << endl;
       }
       */
    // for(row; row < dimension; row++){
    for(col; col < dimension*dimension; col++){
      cin >> temp;
      square.push_back(temp);
    }
    // }

    //    print (square);

    maxsum = square[0];
    for(horzleft = 0; horzleft < dimension - 1; horzleft++){
      for(horzright = 1; horzright < dimension; horzright++){
        for(verttop = 0; verttop < dimension - 1; verttop++){
          for(vertdown = 1; vertdown < dimension; vertdown++){
            temp = sum(horzleft, horzright, verttop, vertdown, square, dimension);
            if(temp > maxsum){
              maxsum = temp;
            }
          }
        }
      }
    }

    cout /*<< "maxsum: " */<< maxsum << endl;
  }
  return 0;


}
