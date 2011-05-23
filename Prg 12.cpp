/** 
Lab Program 12
Inheritance Simulation
Author SkyKOG
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <process.h>

using namespace std;

class STUDENT {

	protected:
		char USN[20],name[20];
		int age;
		
	public:
		void read();
		void display();
};

class UGSTUDENT:public STUDENT {

	int sem;
	float fees,stripend;

	public:
		void read();
		void display();
		template <typename T>
		friend void avg(T &,int);
};

class PGSTUDENT:public STUDENT {

	int sem;
	float fees,stripend;

	public:
		void read();
		void display();
		template <typename T>
		friend void avg(T &,int);
};

void main()
{
	int ch1,i,n;
	UGSTUDENT uobj[10];
	PGSTUDENT pobj[10];

	while(true)
	{	
		system("cls");
		cout<<"1. Undergrad Student\n2. Postgrad Student\n3. Exit\n\nEnter Selection : ";
		cin>>ch1;
		if(ch1==3)
			exit(0);
		
		if(ch1==1)
		{
			system("cls");
			cout<<"\nHow Many Students ? : ";
			cin>>n;
			for(i=0;i<n;i++)
			{
				cout<<"\n\nEnter Details For UG Student : "<<i+1<<"\n";
				uobj[i].read();
			}
			system("cls");
			cout<<"\n\nThe Details of the Students Are : \n";
			cout<<"\nUSN\tName\tAge\tSem\tFees\tStripend\n\n";
			for(i=0;i<n;i++)
			{
				uobj[i].display();
			}
			cout<<"\nAverage Age for Each Sem : ";
			cout<<"\n\nSem\tAverage Age\n";
			avg(uobj,n);
		}

		else if(ch1==2)
		{
			system("cls");
			cout<<"\nHow Many Students ? : ";
			cin>>n;
			for(i=0;i<n;i++)
			{
				cout<<"\n\nEnter Details For PG Student : "<<i+1<<"\n";
				pobj[i].read();
			}
			system("cls");
			cout<<"\n\nThe Details of the Students Are : \n";
			cout<<"\nUSN\tName\tAge\tSem\tFees\tStripend\n\n";
			for(i=0;i<n;i++)
			{
				pobj[i].display();
			}
			cout<<"\nAverage Age for Each Sem : ";
			cout<<"\n\nSem\tAverage Age\n";
			avg(pobj,n);
		}
		else
		{
			cout<<"\nInvalid Selection";
		}
		getch();
	}
}

void STUDENT::read()
{
	cout<<"\nEnter USN : ";
	cin>>USN;
	cout<<"Enter Name : ";
	cin>>name ;
	cout<<"Enter Age : ";
	cin>>age;
}

void STUDENT::display()
{
	cout<<USN<<"\t"<<name<<"\t"<<age<<"\t";
}

void UGSTUDENT::read()
{
	STUDENT::read();
	cout<<"\nEnter Sem : ";
	cin>>sem;
	cout<<"Enter Fees : ";
	cin>>fees;
	cout<<"Enter Stripend : ";
	cin>>stripend;
}

void UGSTUDENT::display()
{
	STUDENT::display();
	cout<<sem<<"\t"<<fees<<"\t"<<stripend<<"\n";
}

void PGSTUDENT::read()
{
	STUDENT::read();
	cout<<"\nEnter Sem : ";
	cin>>sem;
	cout<<"Enter Fees : ";
	cin>>fees;
	cout<<"Enter Stripend : ";
	cin>>stripend;
}

void PGSTUDENT::display()
{
	STUDENT::display();
	cout<<sem<<"\t"<<fees<<"\t"<<stripend<<"\n";
}

template <typename T>
void avg(T &x,int n)
{
	int count[8],sum[8],i;
	
	for(i=0;i<8;i++)
		count[i]=sum[i]=0;
	
	for(i=0;i<n;i++)
	{
		sum[x[i].sem-1]+=x[i].age;
		count[x[i].sem-1]++;
	}

	for(i=0;i<8;i++)
	{
		if(count[i]!=0)
		{
			cout<<"\n"<<i+1<<"\t"<<sum[i]/count[i];
		}
	}
}



/*
License
=======
    Copyright © 2011 SkyKOG

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
