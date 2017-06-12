#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
using namespace std;
// uva problem combination lock - 10550
enum direction {forward, reverse};
int compute_angle(int first, int second, direction dir){
  if (dir == direction::forward){
    if(first < second)
      return first - second + 40;
    else
      return first - second;
  }
  if (dir == direction::reverse){
    if (first > second)
      return second - first + 40;
    else
      return second - first;
  }
}
int main(){
 //   freopen("in.dat", "r", stdin);
  int initial, first, second, third, cumulative;

  while (cin >> initial >> first >> second >> third and
      first + second + third !=0 ){
    direction clockwise = direction :: forward;
    direction anticlockwise = direction :: reverse;
    cumulative += compute_angle(initial,first,clockwise);
    cumulative += compute_angle(first, second,anticlockwise);
    cumulative += compute_angle(second,third,clockwise);
    cumulative += 120;
    cout << 9 * cumulative << endl;
    cumulative = 0;

  }
  return 0;
}
