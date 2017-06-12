#include<iostream>
using namespace std;
double CtoF(double arg){return arg*9/5+32.0;}
double FtoC(double arg){return (arg-32)*5/9;}

int main(){
  cout<<" Please give in a lower limit, limit >= 0: 10"<<endl;
  cout<<" Please give in a higher limit, 10 > limit <= 50000: 20"<<endl;
  cout<<" Please give in a step, 0 < step <= 10: 4"<<endl;
  double x=1.0;
  while (x!=0){
    cin>>x;
    cout<<CtoF(x)<<endl<<"enter 0 to quit";

  }
  return 0;

}


