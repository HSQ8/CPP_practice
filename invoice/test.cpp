#include <iostream>
#include <string>
#include "Invoice.cpp"

using namespace std;
int main(){
  Invoice invoice("4","banana",64,65);
 cout<<invoice.getItemName()<< " costs " <<invoice.getInvoiceAmount()<<endl;

 return 0;

}
