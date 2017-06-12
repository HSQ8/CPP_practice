#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cctype>
#include <cstdio>
using namespace std;
// uva problem word count game-494


int counter(const string& _str){
  int count=0;

  if (isalpha(_str[0]))
    count++;

  for (int it=1; it<_str.length();it++){
    if (isalpha(_str[it]) and !isalpha(_str[it - 1]))
      count ++;
  }
  return count;
}

int main(){
//    freopen("in.dat", "r", stdin);
  string input;

  while(getline(cin,input)){
    cout << counter(input) << endl;
  }
  return 0;
}
