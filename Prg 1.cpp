/**
Lab Program 1 
Simple Class Simulation 1
Author SkyKOG
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class EMPLOYEE {
	int Employee_Number;
	char Employee_Name[20];
	float basic,DA,IT,Net_Salary;

	public:
		void accept();
		void calc();
		void display();
};

void main()
{   	
	system("cls");
	EMPLOYEE emp[20];
	int n;
	cout<<"Enter Number Of Employees : ";
	cin>>n;
	for(int i=0 ; i < n; i++)
	{
		cout<<"\nEnter Details for Emp : "<<i+1<<"\n";
		emp[i].accept();
	}

	cout<<"\n\nNumber\tName\tBasic\tDA\tIT\tNet\n\n";
	for(int i=0 ; i < n ; i++)
	{
		emp[i].display();
	}
	
	getch();
}

void EMPLOYEE::accept()
{
	cout<<"Number : ";
	cin>>Employee_Number;
	cout<<"Name : ";
	cin>>Employee_Name;
	cout<<"Basic : ";
	cin>>basic;
	calc();
}

void EMPLOYEE::calc()
{
	DA=0.52*basic;
	IT=0.30*basic;
	Net_Salary=basic+DA-IT;
}

void EMPLOYEE::display()
{
	cout<<Employee_Number<<"\t"<<Employee_Name<<"\t"<<basic<<"\t"<<DA<<"\t"<<IT<<"\t"<<Net_Salary<<"\n";
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