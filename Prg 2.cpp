/** 
Lab Program 2 
Simple Class Simulation 2
Author SkyKOG
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class STUDENT {
	char USN[20],name[20];
	float m1,m2,m3;

	public:
		void accept();
		int low();
		void display();
		int avg();
};

void main()
{
	system("cls");
	STUDENT stu[10];
	int n;
	cout<<"Enter Number of Students : ";
	cin>>n;
	for(int i=0 ; i < n ; i++)
	{
		cout<<"\nEnter Details For Student : "<<i+1<<"\n";
		stu[i].accept();
	}

	cout<<"\n\nUSN\tName\tAverage Marks\n\n";
	for(int i=0; i < n ; i++)
	{
		stu[i].display();
	}
	
	getch();
}

void STUDENT::accept()
{
	cout<<"USN : ";
	cin>>USN;
	cout<<"Name : ";
	cin>>name;
	cout<<"Marks is 3 Subjects : ";
	cin>>m1>>m2>>m3;
}

void STUDENT::display()
{	
	cout<<USN<<"\t"<<name<<"\t"<<avg()<<"\n";
}

int STUDENT::avg()
{
	return ((m1+m2+m3-low())/2);
}

int STUDENT::low()
{
	if((m1<m2)&&(m1<m3))
		return m1;
	else if(m2<m3)
		return m2;
	else 
		return m3;
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