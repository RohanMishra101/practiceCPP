/*WAP to create a class Emp with data member (id,name,address). Derive a class SALARY with data member(basic_sal,post) 
and again derive class RECORD with data member (month,absent, total) and dispaly employee complete information where
total is calculated by deducing total "absent" days from "basic_sal" */

#include<iostream>
#include<stdlib.h>
using namespace std;

class Emp{
	public:
		string name,address;
		int id;
	public:
		void getInfo()
		{
			fflush(stdin);
			cout<<"-> Enter employee name : ";
			getline(cin, name);
			fflush(stdin);
			cout<<"-> Enter employee id : ";
			cin>>id;
			fflush(stdin);
			cout<<"-> Enter employee address : ";
			getline(cin,address);	
		}	
};

class Salary : public Emp{
	protected:
		string post;
		int basic_sal;
		public:
			void getData()
			{
				cout<<"-> Post : ";
				getline(cin,post);
				fflush(stdin);
				cout<<"-> Salary : ";
				cin>>basic_sal;	
			}
};

class Record : public Salary{
	int absent,month;
	double total;
	public:
		void getPaid()
		{
			int total_days;
			double per_daySal;
			cout <<"Enter total worked Month: ";
			cin>>month;
			cout <<"Enter total absent days: ";
			cin>>absent;
			per_daySal = basic_sal/30;
			total_days = (month*30)-absent;
			total = total_days * per_daySal;
		}
		void putInfo(){
			cout <<"-->Name :"<<name<<endl;
			cout <<"-->Id : "<<id<<endl;
			cout <<"-->Address : "<<address<<endl;
			cout <<"-->Post : "<<post<<endl;
			cout <<"-->Salary: "<<basic_sal<<endl;
			cout <<"Total salary to receive : "<<total<<endl;	
		}
};	

int main()
{
	Record obj[10];
	string name1;
	int i=0,n,count=0,id1;
	char c;
	cout<<"Enter the total number of Employee detail to store: ";
	cin>>n;
	for(i=0;i<n;i++){
		cout<<endl<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout<<"-> Enter "<<i+1<<" Employee's Detail : "<<endl;
		obj[i].getInfo();
		cout<<endl<<"=-=-=-=-="<<endl<<"-> Enter post and basic salary of the Employee : "<<endl;
		obj[i].getData();
	}
	cout<<endl<<"--> Information stored!!"<<endl<<"Press 1 and ENTER key to calculate the total salary of the Employee : ";
	cin >> c;
	system("cls");
	fflush(stdin);
	cout<<"->Enter Name and id of Employee to calculate total salary: "<<endl;
	cout<<"->Name : ";
	getline(cin,name1);
	fflush(stdin);
	cout<<"->Id : ";
	cin>>id1;
	fflush(stdin);
	try{
		for(i=0;i<n;i++)
		{
			if(obj[i].name == name1 && obj[i].id == id1)
			{
				obj[i].getPaid();
				obj[i].putInfo();
			}
			else{
				count++;
			}
		}
		if(count == n)
		{
			throw "The provided Name and Id does not exist!!";
		}
	}catch(const char* msg){
		cerr<< msg<<endl;
	}
	return 0;
}
