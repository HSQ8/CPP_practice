#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
using namespace std;
// uva problem 500!- 623
void print(vector<int>&);

void multiply2(vector<int>& v, const int& mult){
  for(int i=0; i<v.size(); i++){
    int carry = 0;
    int temp = v[i]*mult;
      v[i]=(temp % 100000)+carry;
    temp+=carry;
      while (temp > 99999){
      temp /= 100000;
      if(i == v.size()-1){
        v.push_back(temp);
        carry = 0;
      }
      else
        carry=temp;
      }
  }
}

void multiply3(vector<int>& _vec, const int& mult){

  long int product, carry;

  for (int i = 0; i<_vec.size(); ++i){
    carry = 0;
    product = 0;

    product = _vec[i]*mult;
    _vec[i] = product % 1000 +carry;
    carry = _vec[i] / 1000;
      if (carry > 0 and i == _vec.size()-1){
        _vec.push_back(carry);
        carry=0;
      }
      else if (carry > 0 and _vec[i+1] != 0)
        _vec[i+1] += carry;
    carry=0;

  }

}


void multiply(vector<int>& v, const int mult)
{
  vector<int>::iterator it = v.end()-1;
  int product= (*it)*mult;// 1st term explicitly
  int carry = product/1000;
  *it = product%1000;

  while( it != v.begin() )
  {
    --it;// so v.begin will be included
    product = (*it)*mult + carry;
    carry = product/1000;
    *it = product%1000;

  }

  while( carry > 0 )// push_front the carry
  {
    v.insert( v.begin(), carry%1000 );
    carry /= 1000;
  }
}
void performFactorial(vector<int>& _vec, const int& _base){
  _vec.insert(_vec.begin(),1);
  for (int i=2; i<_base+1; i++){
    multiply3(_vec,i);
  }
}

void print(vector<int>& _vec){
  for(vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
    cout << *it;
  cout << endl;
}

int main(){
    //freopen("in.dat", "r", stdin);
  int base;
  vector<int> factorialNum;
  while(cin >> base){
        performFactorial(factorialNum,base);
        cout << base << "!"<< endl;
        print(factorialNum);
        factorialNum.clear();
  }
  return 0;
}
