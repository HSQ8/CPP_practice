#include<iostream>
#include<string>
#include<sstream>

using namespace std;


int main()
{
  int i;
  cout << "answer this problem"<<"5*6+7-8"<<"and give its value below" << endl;
  start:
  cin>>i;
  switch (i)
  {
    case 29:
      cout<<"you are correct!\n";
      break;
    default:
      cout<<"try again\n";
      goto start;
  }
  return 0;


}
