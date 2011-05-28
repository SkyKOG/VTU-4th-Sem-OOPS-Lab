/**
Lab Program 8
Operator Overloading - Matrix Class
Author SkyKOG
*/

#include <iostream>
#include <Windows.h>
#include <process.h>
#include <conio.h>

#define MAX 10

using namespace std;

class MATRIX {

	int arr[10][10],row,col;

	public : 
		void input();
		bool operator ==(MATRIX);
		MATRIX operator +(MATRIX);
		MATRIX operator -(MATRIX);
		friend void operator <<(ostream &,MATRIX &);

};

void main()
{
	system("cls");
	MATRIX m1,m2,m3,m4;
	int ch;

	while(1)
	{
		system("cls");
		cout<<"1. Insert\n2. Add\n3. Subtract\n4. Exit\n\nEnter Your Choice : ";
		cin>>ch;
		cout<<"\n";

		switch(ch)
		{
		case 1:cout<<"Enter Details For Matrix 1 : ";
			m1.input();
			cout<<"\nThe Contents Are : \n";
			cout<<m1;

			cout<<"\n\nEnter Details For Matrix 2 : ";
			m2.input();
			cout<<"\nThe Contents Are : \n";
			cout<<m2;
			break;

		case 2:if(m1==m2)
				{
				   m3=m1+m2;
				   cout<<"The Result is Of the Addition is : \n";
				   cout<<m3;
				}
			   else
				   cout<<"Fail : Matrix Orders does not Match";
			break;

		case 3:if(m1==m2)
				{
				   m4=m1-m2;
				   cout<<"The Result of the Subtraction is : \n";
				   cout<<m4;
				}
			   else
				   cout<<"Fail : Matrix Orders does not Match";
			break;

		case 4:exit(0);
			break;

		default:cout<<"Invalid Selection\n";
			break;
		}
		getch();
	}
}


void MATRIX::input()
{
	cout<<"\nEnter Row & Column for the Matrix : ";
	cin>>row>>col;
	cout<<"Enter Elements : ";
	for(int i =0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			cin>>arr[i][j];
		}
	}
}

bool MATRIX::operator==(MATRIX m2)
{
	if((row==m2.row)&&(col==m2.col))
		return true;
	return false;
}

MATRIX MATRIX::operator +(MATRIX m2)
{
	MATRIX m;
	m.row=row;
	m.col=col;
	for(int i =0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			m.arr[i][j]=arr[i][j]+m2.arr[i][j];
		}
	}
	return m;
}

MATRIX MATRIX::operator -(MATRIX m2)     
{
	MATRIX m;
	m.row=row;
	m.col=col;
	for(int i =0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			m.arr[i][j]=arr[i][j]-m2.arr[i][j];
		}
	}
	return m;
}

void operator <<(ostream &out,MATRIX &m)
{
	for(int i =0 ; i < m.row ; i++)
	{
		for(int j = 0 ; j < m.col ; j++)
		{
			out<<m.arr[i][j]<<" ";
		}
		cout<<"\n";
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