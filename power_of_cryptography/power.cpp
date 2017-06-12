#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;
// uva problem power of cryptography 113

int main(){
 // freopen("in.dat", "r", stdin);
  long double exp, base;
  while (cin >> base){
    cin >> exp;
    base=1/base;
    cout << round(pow(exp,base)) << endl;
  }
  return 0;
}
