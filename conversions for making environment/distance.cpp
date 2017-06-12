#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int main(){
  cout << fixed;
  double num;
  do{
    cout<<"enter conversion pixel here";
      cin>>num;
      cout<<"converted is "<<(num*10/779)<<endl;

  }while(num!=0);
  return 0;
}





