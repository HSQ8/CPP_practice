#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
using namespace std;
class LinkedList {

  public:
    LinkedList(int T=5){
      this->data = T;
    }


    LinkedList* next;
    LinkedList* previous;
    int returnData(){return data;}
  private:
    int data;

};


int main(){
  LinkedList* root;
  root = new LinkedList;
  cout << root -> returnData();



  return 0;
}
