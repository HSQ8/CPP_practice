#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int main()
{
  int count=0;
  cout<<"enter a string here to get its permutations"<<endl;
  string s;
  getline(cin,s);
  sort(s.begin(), s.end());
  do {
    cout << s << '\n';
count++;
  } while(next_permutation(s.begin(), s.end()));
  cout<<" the total number of permutations is: "<<count<<endl;
}
