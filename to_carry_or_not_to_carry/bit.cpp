#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
#include <cmath>
using namespace std;
// uva problem to carry or not to carry 10469


template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
  out << "[";
  size_t last = v.size() - 1;
  for(size_t i = 0; i < v.size(); ++i) {
    out << v[i];
    if (i != last)
      out << ", ";
  }
  out << "]";
  return out;
}


vector<int> convertToBinary(int& _num){
  // _num +=1;
  int a = 32;
  vector<int> result;
  while(a){
    result.push_back(0);
    --a;
  }
  int length = log(_num)/log(2);

  while(length + 1 > 0){
    if(_num >= (int)(pow(2,(double)length))){
      result[length]=1;
      _num -= (int)(pow(2,(double)length));
    }
    --length;
  }
  return result;
}

int convertToDecimal(vector<int>& _result){
  int cumulative = 0;
  for(int i = 0; i < 32; ++i){
  cumulative += pow(2,i)*_result[i];
  }
return cumulative;
}

vector<int> performBitWise(const vector<int>& _avec, const vector<int>& _bvec){
   int a = 32;
  vector<int> result;
  while(a){
    result.push_back(0);
    --a;
  }

  for(int i = 0; i < 32; ++i){
    if(_avec[i] xor _bvec[i])
      result[i]=1;
  }
  return result;
}


int main(){
  // freopen("in.dat", "r", stdin);

  int a, b, out;
  while (cin >> a >>b){
    vector<int> avec = convertToBinary(a);
    vector<int> bvec = convertToBinary(b);
    vector<int> result = performBitWise(avec,bvec);

  cout << convertToDecimal(result) << endl;
  }


  return 0;
}
