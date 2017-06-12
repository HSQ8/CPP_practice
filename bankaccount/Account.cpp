#include<iostream>
#include<vector>
#include<string>
#include "Account.h"
using namespace std;

Account::Account(int balance){
  if(balance>=0)
    setBalance(balance);
  else
    cout<<"invalid number, it must be positive amount. automatically setting 0 for balance"<<endl;
  setBalance(0);
}
void Account::setBalance(int bal){balance=bal;}
int Account::getBalance(){return balance;}
void Account::display() {cout<<"the balance is"<<getBalance()<<endl;}
void Account::Debit(int deb){
  if(deb>balance)
    balance=0;
  else
    balance-=deb;
}
void Account::Credit(int cre){balance+=cre;}




