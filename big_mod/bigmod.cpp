#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
#include <cmath>
using namespace std;
// uva problem 374- big mod
int main(){
  //freopen("in.dat", "r", stdin);
  long int B, P, M, multiplier;
  while (cin >> B >> P >> M){
    multiplier = 1;
    while(P != 1 and P != 0 and B != 1 ){
      cout << "P" << P << endl;
      int exp = (int)ceil(log(M)/log(B));
      //multiplier = ((int)((double)multiplier * pow((double)B,(pow((double)M,(double)exp))))) % M;
      multiplier = ((int)((double)multiplier * pow((double)B,(double)(P % exp)))) % M;
      P = P / exp;
      B = ((int)pow((double)B, (double)exp)) % M;
      cout << "B" << B << endl;
      cout << "P" << P << endl;
      cout << "exp" << exp << endl;
      cout << "M" << M << endl << endl;
      cin.ignore();
    //  if(P == 0)
//        break;
    }
    if(P != 0)
      cout << (multiplier * B) % M << endl;
    else
      cout << 1;
  }
  return 0;
}
