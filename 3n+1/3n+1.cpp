#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
using namespace std;
// uva problem 100

int main(){
  int count, num, start, finish, max, astart, afinish;
  while (cin >> start >> finish){

    astart=start;
    afinish=finish;

    max=0;
    if (start > finish){
      num=start;
      start=finish;
      finish=num;
    }

    for(int n=start; n <finish+1; n++){
      count = 1;
      num=n;
      while( num != 1){
        if(num%2 == 1 )
          num=3*num+1;
        else
          num/=2;
        count ++;
      }
      if (max < count)
        max=count;
    }

    cout << astart << " " << afinish << " " << max << endl;
  }
  return 0;
}
