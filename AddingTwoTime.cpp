//WAP to add two times in hour and minutes illustrating passing object as function argument.

#include<iostream>
using namespace std;

class Time{
	int hour;
	int min;
	
	public:
		void getData()
		{
			cout << "Enter Time" << endl;
			cout << "Hour : ";
			cin>> hour;
			cout << "Minute : ";
			cin>> min; 
		}
		Time calc(Time obj1[2])
		{
			int count;
			Time obj3;
			
			obj3.hour = obj1[0].hour + obj1[1].hour;
			obj3.min = obj1[0].min + obj1[1].min;
			
			while(obj3.min > 60)
			{
				obj3.min -=60;
				count++;
			}
			obj3.hour  += count;
			return obj3;
		}
		void putData()
		{
			cout <<"Added Hour is : "<< hour << endl;
			cout <<"Added Minute is : " << min << endl;
		}
};

int main()
{
	Time obj[2];
	Time obj1;
	int i=0;
	
	for(i=0;i<2;i++)
	{
		cout <<"Time " << i+1 <<" : ";
		obj[i].getData();
	}
	obj1 = obj[0].calc(obj);
	obj1.putData();
	return 0;
	
	
}
