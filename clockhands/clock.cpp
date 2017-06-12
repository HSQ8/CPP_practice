#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;
// uva problem

int main(){
   // freopen("in.dat", "r", stdin);

  cout << fixed << setprecision(3);
  string time;
  while(getline(cin, time) and time != "0:00" and time != ""){
    const size_t position = time.find(":");
    double hour = stod(time.substr(0,position));
    double minute = stod(time.substr(position+1,2));
    double answer = abs((hour+minute/60)*30-minute*6);
    if (answer > 180)
      answer = 360-answer;
    cout << answer << endl;
  }
  return 0;
}
