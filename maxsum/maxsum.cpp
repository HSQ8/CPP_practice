#include<iostream>
#include<vector>
using namespace std;

int max_sum(vector<int> arr)
{
  int best = 0, current = 0;
  for(int i = 0; i <arr.size(); i++)
  {
    if(arr[i]>0)
      best+=arr[i];
  }
  return best;
}

int main(){


  int myints[] = {16,2,77,29,-63,-2,5,6};
  vector<int> arr (myints, myints + sizeof(myints) / sizeof(int) );

  cout<<max_sum(arr)<<endl;
  return 0;

}
