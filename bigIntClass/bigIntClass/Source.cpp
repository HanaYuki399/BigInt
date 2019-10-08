////////////////////////////////////////////////////////
//////////Main.cpp///////////////////
#include <iostream>
using namespace std;
#include <conio.h>
#include<string>

#include "bigInt.h"
int main()
{
	
	string b = "10000000000000000000";//for the default parameterized value
	BigInt num1(b), num2(b), sum, diff;
	 
	char select = '0';
	int obi = 0;
	cout << "\n\n                              xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n ";
	cout << "\n\n                              xxxxxxx Big Integer Addition & Subtraction xxxxxx\n";
	cout << "\n\n                              xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx ";
	cout << "\n\n\n";
	char n='0';
	char k;

	do                                //loop for the repitition of the whole program
	{
		cout << "Enter Big Integer 1 : " ;
		num1.setStr();
		cout << endl;
		cout <<"The First Big Integer is: "<< num1.getStr();
		cout << endl;
		cout << "Enter Big Integer 2 : ";
		num2.setStr();
		cout << endl;
		cout <<"The Second Big Integer is: "<< num2.getStr();
		cout << endl;
		do                           //loop for applying other functions on the current values
		{
			cout << "Press 1 if you want to display their sum.\nPress 2 if you want to display their difference\n\n";
			cin >> select;
			if (select == '1')
			{
				sum = num1 + num2;
				cout << sum;
				cout << endl;
			}
			else if (select == '2')
			{
				diff = num1 - num2;
				cout << diff;
				cout << endl;
			}
			
			else {
				cout << "Wrong Input,Enter again.\n\n";//for when the user inputs something other that '1' or '0'
				cout << endl;
				obi = 1;
			}
			if (obi == 0)
			{
				cout << "Press 'y' if you would you like to perform another operation on these numbers.\n\nPress 'n' if you dont.\n\n";
				cin >> k;
				if (k == 'y')
				{
					select = '0';
				}
				
			}
			obi = 0;

		} while (select != '1' && select != '2');

		cout << "Press y if you would like to enter more inputs.\n\nPress 'n' and then enter if you would like to terminate the program\n\n";
		cin >> n;
	}
	while (n == 'y');

	_getch();
	
	return 0;
}