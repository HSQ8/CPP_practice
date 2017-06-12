#include "Invoice.h"



Invoice :: Invoice(string num1,string name,int num,int num3){
 setItemNumber(num1);
 setItemName(name);
 setUnitPrice( num);
 setUnitQuantity( num3);
}


string Invoice :: getItemNumber(){return itemNumber;}
string Invoice :: getItemName(){return itemName;}
int Invoice :: getUnitPrice(){return unitPrice;}
int Invoice :: getUnitQuantity(){return quantity;}

void Invoice :: setItemNumber(string num){itemNumber=num;}
void Invoice :: setItemName(string name){itemName=name;}
void Invoice :: setUnitPrice(int num){unitPrice=num;}
void Invoice :: setUnitQuantity(int num){quantity=num;}


int Invoice ::  getInvoiceAmount(){return quantity*unitPrice;}




