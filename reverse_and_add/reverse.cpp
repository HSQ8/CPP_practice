#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
using namespace std;
// uva problem 10018- Reverse and Add
int count = 0;

void flip(string& _str){
  string temp = _str;
  for(string::size_type i = 0; i<temp.length(); i++)
    _str[i] = temp[temp.length() - i - 1];
}

bool check(string _str){
  string temp = _str;
  flip(_str);
  return (_str == temp);
}

void reverseAndAdd(long int& num){
  string current = to_string(num);
  count = 0;
  do{
    flip(current);
    num += stol(current);
    current = to_string(num);
    count++;
  }while(!check(current));
}

int main(){
//  freopen("in.dat", "r", stdin);

  long int trials, num;
  cin >> trials;

  while(trials > 0 and cin >> num ){
    reverseAndAdd(num);
    cout << count << " " << num << endl;
    trials--;
  }
  return 0;
}
