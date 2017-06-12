#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
using namespace std;
// uva problem relational operators - 11172

int main(){
  //  freopen("in.dat", "r", stdin);
  int first,second,count;
  cin >> count;
  while (count > 0 and cin>>first >> second){
    if(first > second) cout << ">" << endl;
    else if(first < second) cout << "<" << endl;
    else cout << "=" << endl;
  count--;
  }

  return 0;
}
