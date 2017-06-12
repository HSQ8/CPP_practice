#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;


int main(/*t argc, char** argv*/){
  clock_t t1,t2;
  t1=clock();
  string cmd;
  cout <<" enter command here :"<< endl;
  getline (cin,cmd);
  cout <<"executing "<< cmd << endl;
  system(cmd.c_str());
  t2=clock();
  double diff = ((double)t2-(double)t1);

  cout<<"time elapsed"<< fixed << setprecision(10)<<diff<<endl;
  return 0;

}
