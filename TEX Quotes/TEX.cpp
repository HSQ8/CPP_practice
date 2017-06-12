#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;
// uva problem 272 TEX Conversions
string replaceQuote(string&);



int main(){
  freopen("in.dat", "r", stdin);
  string text;
  while(getline(cin, text)){
    cout << replaceQuote(text)<<endl;
  }

  return 0;
}


string replaceQuote(string& _str){
  int counter = 0;
  for (string::size_type i = 0; i < _str.length(); i++){
    if (_str[i] == '"' and counter%2 == 0){
      _str.erase(i,1);
      _str.insert(i,"``");

      counter ++;
      i+=1;
    }else if(_str[i] == '"' and counter%2 == 1){
      _str.erase(i,1);
      _str.insert(i,"''");
      counter ++;
      i+=1;
    }

  }
  return _str;
}



