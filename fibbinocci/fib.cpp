#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#define Phi (sqrt(5)+1)/2
#define phi (sqrt(5)+1)/2


using namespace std;
int recursive(int _num){
  if(_num<0)
    return 0;
  if(_num==0 or _num == 1)
    return 1;
  if(_num>1)
    return recursive(_num-1)+recursive(_num-2);
}


double betterfib(int _num){
  vector<double> myvec;

  myvec.push_back(1.0);
  myvec.push_back(1.0);
  for (int i=2;i<_num;i++)
    myvec.push_back(myvec[i-1]+myvec[i-2]);
  return myvec[_num-1];
}

long double bestfib(int _num){





}

int main(){
  cout << fixed;
  cout<<"enter the index of fibbonacci number here, and it will calculate said number"<<endl;
  int num;
  do{
    cin>>num;
    cout<<"num: "<<num<<endl;
//    cout<< recursive(num)<<endl;
    cout<< betterfib(num+1)<<endl;
  }while(num!=0);
  return 0;
}





