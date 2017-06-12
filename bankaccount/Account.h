#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Account {
  public:
    Account(int);
    void Debit(int);
    void Credit(int);
void setBalance(int);
    int getBalance();
    void display();
  private:
    int balance;
};


