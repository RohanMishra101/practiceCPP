//WAP to concatinate two string by overloading binary operator + (using string class) / (char).

#include<iostream>
using namespace std;

class Det{
	string name;
	public:
		void getString(string str)
		{
			name = str;
		}
		void displayString()
		{
			cout<<name;
		}
		Det operator + (const Det &str)
		{
			Det temp;
			temp.name = this->name + " " + str.name;
			return temp;
		}
};
int main()
{
	Det obj1,obj2,result;
	string str1;
	cout << "Enter first String: ";
	getline(cin,str1);
	obj1.getString(str1);
	cout << "Enter second String: ";
	getline(cin,str1);
	obj2.getString(str1);
	result = obj1 + obj2;
	result.displayString();
	return 0;
}
