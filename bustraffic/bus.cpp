#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;
// uva problem



vector <int> readString(string& _pas){
  vector <int> tempcount;
  while (_pas.length() != 0){
    size_t pos = _pas.find(" ");
    tempcount.push_back(stoi(_pas.substr(0,pos)));
    _pas = _pas.substr(pos+1, _pas.length()-pos);
  }
  return tempcount;
}

vector<int> producePas(vector<int>& _pcount){
  vector<int> trip;
  trip.push_back(_pcount[1]);
  _pcount.erase(trip.begin());
  while(_pcount.size() > 1){
    trip.push_back(_pcount[1]+_pcount[2]);
    _pcount.erase(trip.begin());
    _pcount.erase(trip.begin());
  }
  return trip;
}

vector<int> findMin(vector<int>& _tripleg){
  vector<int> result;
  int min= _tripleg[0];
  for (int i=0; i<_tripleg.size(); ++i){
    if(_tripleg[i] < min);
    min=_tripleg[i];
  }

  for(int i=0; i<_tripleg.size(); ++i){
    if (_tripleg[i] == min)
      result.push_back(i);

  }
  result.push_back(min);
  return result;
}

int main(){
  freopen("in.dat", "r", stdin);
  int busses;
  vector <int> pcount;
  cin >> busses;
  while (busses > 0){
    string passengers;
    getline(cin, passengers);
    vector <int> pcount = readString(passengers);
    vector <int> tripleg = producePas(pcount);
    vector<int> result = findMin(tripleg);

    for(int i=0; i<result.size()-1; ++i){
      char out= result[i]+65;
      cout << out << " ";
    }
    cout << *result.end() << endl;
    --busses;
  }
  return 0;
}
