#include <iostream> 

using namespace std;

int main()
{
  	 
  float a, b, result;
	char oper, clear;
	cout << "Please enter an equation: i.e 5+5 " << endl;
	for (;;) {
		  cin >> a;
		  cin >> oper;
		  cin >> b;
		 if (oper == '+')
        result = a + b;
		 else if (oper == '-')
		    result = a - b;
	   else if (oper == '*')
			  result = a * b;
     else if (oper == '/')
			  result = a / b;	
    cout << "= " << result << endl << endl;
    cin.clear();
    cin.ignore();
   } 
} 
