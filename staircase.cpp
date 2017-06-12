#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
using namespace std;
// uva problem staircase

int main(){
  //  freopen("in.dat", "r", stdin);
  int n,j,m;
  cin>>n;
  m=n-1;
  for (int i=1;i<=n;i++){
    while (m>0){
      cout<< " ";
      m--;
    }
    for(j=1;j<=i;j++){
      cout << "#";
    }
    m=n-j;
    cout << endl;
  }
  return 0;
}
