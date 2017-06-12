#include<iostream>
#include<string>
//#include<sstream>
//#include<vector>
//#include<algorithm>
//#include<iterator>

using namespace std;
int main (){
  int max;
  int array[]={1,2,-5,4,-3,2};
  for (int n=0;n<6;n++) {
  if (array[n]>0)
    max+=array[n];
  else
    max+=0;



  }
  int a(max);
  cout<<"the max sum is"<<a<<endl;
  return 0;
}








