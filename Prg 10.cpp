/**
Lab Program 10
Templatised Queue 
Author SkyKOG
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <process.h>

#define MAX 10

using namespace std;

template <class T>
class queue {

	int f,r;
	T arr[MAX];

	public:
		void insq(T);
		void delq();
		queue();
		void display();
};

void main()
{

	int ch,ch2,iele;
	double dele;

	queue<int> iobj;
	queue<double> dobj;

	cout<<"1. Integer Queue\n2. Double Queue\n\nEnter Selection : ";
	cin>>ch;

	system("cls");

	while(true)
	{
		system("cls");
		cout<<"1. Insert Element\n2. Delete Element\n3. Display\n4. Exit\n\nEnter Selection : ";
		cin>>ch2;
		switch(ch2)
		{
		case 1:cout<<"\nEnter Element to be Inserted : ";
			if(ch==1)
			{
				cin>>iele;
				iobj.insq(iele);
			}
			else 
			{
				cin>>dele;
				dobj.insq(dele);
			}
			break;

		case 2:if(ch==1)
				   iobj.delq();
			   else
				   dobj.delq();
			break;

		case 3:if(ch==1)
				   iobj.display();
			   else
				   dobj.display();
			break;
			
		case 4:exit(0);
			break;

		default:cout<<"Invalid Selection";
			break;
		}
		getch();
	}
}

template <class T>
queue<T>::queue()
{
	f=0;
	r=-1;
}

template <class T>
void queue<T>::insq(T ele)
{
	if(r==MAX-1)
	{
		cout<<"\nQueue Full";
		return;
	}
	arr[++r]=ele;
	display();
}

template <class T>
void queue<T>::delq()
{
	if(f>r)
	{
		cout<<"\nQueue Empty";
		return;
	}
	cout<<"\nElement Deleted is : "<<arr[f++];
	if(f>r)
	{
		f=0;
		r=-1;
	}
	display();
}

template <class T>
void queue<T>::display()
{
	int i;
	if(f>r)
	{
		cout<<"\nEmpty Queue";
		return;
	}
	cout<<"\n\nThe Contents of the Queue Are : ";
	for(i=f;i<=r;i++)
	{
		cout<<arr[i]<<" ";
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