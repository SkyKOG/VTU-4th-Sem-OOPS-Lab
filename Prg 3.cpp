/** 
Lab Program 3
Member Fuction Overloading n Friend Funcs 
Author SkyKOG
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <process.h>

using namespace std;

class COMPLEX {
	int real,img;

	friend COMPLEX ADD(int,COMPLEX &);
	friend COMPLEX ADD(COMPLEX &,COMPLEX &);
		
	public:
		void accept();
		void display();
};

void main()
{
	COMPLEX s1,s2,s3;
	int real;
	int ch;
	while(true)
	{
		system("cls");
		cout<<"1. ADD(int,COMPLEX)\n2. ADD(COMPLEX,COMPLEX)\n3. Exit\n\nEnter Choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1:cout<<"\n\nEnter Integer Real Part : ";
			cin>>real;
			cout<<"\nEnter Data for COMPLEX S2 : \n";
			s2.accept();
			cout<<"\nS2 : ";
			s2.display();
			s3=ADD(real,s2);
			cout<<"\n\nThe Addition Result : ";
			s3.display();
			break;
		case 2:cout<<"\n\nEnter Data for COMPLEX S1 : \n";
			s1.accept();
			cout<<"\nEnter Data for COMPLEX S2 : \n";
			s2.accept();
			cout<<"\nS1 : ";
			s1.display();
			cout<<"\nS2 : ";
			s2.display();
			s3=ADD(s1,s2);
			cout<<"\n\nThe Addition Result : ";
			s3.display();
			break;
		case 3:exit(0);
			break;
		default:cout<<"Invalid Selection";
			break;
		}
		getch();
	}
}
			
COMPLEX ADD(int real,COMPLEX &s1)
{
	COMPLEX temp;
	temp.real=real+s1.real;
	temp.img=s1.img;
	return temp;
}

COMPLEX ADD(COMPLEX &s1,COMPLEX &s2)
{
	COMPLEX temp;
	temp.real=s1.real+s2.real;
	temp.img=s1.img+s2.img;
	return temp;
}

void COMPLEX::accept()
{
	cout<<"Enter Real Part : ";
	cin>>real;
	cout<<"Enter Imaginary Part : ";
	cin>>img;
}

void COMPLEX::display()
{
	cout<<real<<" +i"<<img;
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