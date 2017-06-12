#include <iostream>
#include <string>
using namespace std;


class Invoice{
  private:
    string itemNumber;
    string itemName;
    int quantity;
    int unitPrice;
  public:
    Invoice(string num1, string name, int num, int num3);
    string getItemNumber();
    string getItemName();
    int getUnitPrice();
    int getUnitQuantity();


    void setItemNumber(string num);
    void setItemName(string name);
    void setUnitPrice(int num);
   void setUnitQuantity(int num);


    int getInvoiceAmount();



};
