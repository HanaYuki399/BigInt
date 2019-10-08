///////////////////////////////////////////////////////
///////////////bigInt.h///////////////
class BigInt

{

	string s;
	

public:
	//Basic member functions
	BigInt();//default constructor,sets the initial value of the private member to null or zero.
	BigInt(string);// parameterized constructor, sets the initial value of the private member to users choice.
	void setStr();//sets value of the string by input method
	string getStr();//gets value of the string

	//Operative member functions 
	BigInt addBigInts(BigInt, BigInt);//function to add two big integers.
	BigInt subtractBigInts(BigInt, BigInt);//function to add two big integers.
	BigInt operator  +(const BigInt &);//operator to add two big integers.
	BigInt operator-(const BigInt &);//operator to add two big integers.
	friend istream & operator >>(istream &, BigInt &);//operator to take big integer as input.
	friend ostream & operator <<(ostream &, BigInt &);//operator to display big integer as output.



};
