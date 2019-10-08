///////////////////////////////////////////////////////////////
/////////////bigint.cpp///////////

#include <iostream>
using namespace std;
#include<string>
#include <conio.h>
#include "bigInt.h"

BigInt::BigInt()
{
	s = "0";
}

BigInt::BigInt(string a)
{
	s = a;
}

void BigInt::setStr()
{
	cin >> s;
	
}

string BigInt::getStr()
{
	return s;
}

BigInt BigInt::subtractBigInts(BigInt one, BigInt two)
{
	int fir = one.s.length();
	int sec = two.s.length();
	int c;
	string first;
	string second;
	//We'll be setting the second string to be the larger one out of both.
	//the following conditions will return 'c=1' only if the fir string is larger,else,if its smaller or equal to it,it will return c as '0'
	if (fir < sec)
	{
		c = 1;

	}

	else if (sec < fir)
	{
		c = 0;

	}

	if (fir == sec)
	{
		for (int i = 0; i<fir; i++)
		{
			if (one.s[i] < two.s[i])
			{
				c = 1;

				cout << c << endl;
				break;
			}
			else if (one.s[i] > two.s[i])
			{
				c = 0;

				cout << c << endl;
				break;
			}
			else if (i == (fir - 1))
			{
				c = 0;

				cout << c << endl;
			}
		}
	}
	BigInt str;
	str.s= "";
	//Now we'll be setting the larger string as string second and the smaller one as string first 
	if (c == 0)
	{
		first = two.s;
		second = one.s;

	}
	else if (c == 1)
	{
		first = one.s;
		second = two.s;
	}


	int len1 = first.length(), len2 = second.length();
	//reversing the strings so that instead of subtracting from the end of the string,we subtract from the start
	for (int o = 0; o < len1 / 2; o++)
		swap(first[o], first[len1 - o - 1]);
	for (int w = 0; w < len2 / 2; w++)
		swap(second[w], second[len2 - w - 1]);

	int borrow = 0;
	int dif1;
	int dif2;
	int strt;
	int subt;
	for (int i = 0; i<len1; i++)//loop goes on when both the integers have numbers that can be added
	{
		dif2 = second[i] - '0';//changing character to integer
		dif1 = first[i] - '0';
		strt = (dif2 - dif1);
		subt = strt - borrow;//subtract the borrow from the number incase it has been taken 
		if (subt < 0)
		{
			subt = subt + 10;
			borrow = 1;//borrow exists if the answer is negative
		}
		else
			borrow = 0;

		str.s.push_back(subt + '0');//function that pushes character to the end of the string,after pushing all the characters,we'll be reversing the new string
	}
	for (int i = len1; i<len2; i++)//loop goes on for the integer whose length is longer
	{
		dif2 = second[i] - '0';
		int subt = dif2 - borrow;
		if (subt < 0)
		{
			subt = subt + 10;
			borrow = 1;
		}
		else
			borrow = 0;

		str.s.push_back(subt + '0');
	}
	if (c == 1)//for negative answer
	{
		str.s.push_back('-');
	}
	int y = str.s.length();
	for (int g = 0; g < y / 2; g++)
		swap(str.s[g], str.s[y - g - 1]);//reversing the new string

	return str;
	
}

BigInt BigInt::addBigInts(BigInt one, BigInt two)
{
	BigInt res;
	res.s = "";

	string first;
	string second;
	if (one.s.length() >= two.s.length())//checking the longer integer so that we can set the for loops
	{
		first = two.s;
		second = one.s;
	}
	else if (two.s.length()>one.s.length())
	{
		first = one.s;
		second = two.s;
	}
	int a = first.length();
	int b = second.length();



	for (int i = 0; i < a / 2; i++)//reversing the strings
		swap(first[i], first[a - i - 1]);



	for (int k = 0; k < b / 2; k++)
		swap(second[k], second[b - k - 1]);



	int carry = 0;
	int rem = 0;
	int s1;
	int s2;
	for (int i = 0; i<a; i++)
	{
		s1 = first[i] - '0';
		s2 = second[i] - '0';
		int sum = (s1 + s2 + carry);//adds the carry if it receives any
		rem = sum % 10;
		res.s.push_back(rem + '0');

		carry = sum / 10;

	}
	rem = 0;
	for (int i = a; i<b; i++)
	{

		s1 = second[i] - '0';
		int sum = (s1 + carry);
		rem = sum % 10;
		res.s.push_back(rem + '0');
		carry = sum / 10;
	}

	if (carry)
	{
		res.s.push_back(carry + '0');
	}
	int len = res.s.length();

	for (int p = 0; p < len / 2; p++)
		swap(res.s[p], res.s[len - p - 1]);//reversing the new string



	return res;
	
}

BigInt BigInt::operator +(const BigInt &p)//operator of addition that adds two bigInts
{
	BigInt yuki=addBigInts(s, p.s);
	return yuki;
	
	
}

BigInt BigInt::operator-(const BigInt &p)//operator of subtraction that subtracts two bigInts
{
	BigInt sub;
	sub= subtractBigInts( s, p.s);
	return sub;
		
}
istream & operator>>(istream &i, BigInt &p)
{

	i >> p.s;//taking input of string

	return i;
}
ostream & operator <<(ostream &i, BigInt &p)

{
	i << p.s;//displaying output of string
	return i;
}


