#include <algorithm>
#include <string>
#include <iostream>
using namespace std;



void swap(string& _s, int index){
char temp;
temp=_s[index];
_s[index]=_s[index+1];
_s[index+1]=temp;
}


void permute(string& _s){





}

int main(){
  int count=0;
  cout<<"enter a string here to get its permutations"<<endl;
  string s;
  getline(cin,s);
  int length=s.length();
  cout<<length<<endl;
swap(s, 2);
cout<<s;
}




