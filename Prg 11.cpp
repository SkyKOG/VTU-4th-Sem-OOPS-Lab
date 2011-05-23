/**
Lab Program 11
Double Link List Implementation
Author SkyKOG
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <process.h>

using namespace std;

class DLIST {

	struct node
	{
		int item;
		node *l;
		node *r;
	}*p;

	public:	
		DLIST();
		void ipos(int,int);
		int dpos(int,int &);
		void display();
		~DLIST();
};

void main()
{
	DLIST obj;
	int ch,ele,pos,status=0;
	while(true)
	{
		system("cls");
		cout<<"1. Insert At Pos\n2. Delete From Pos\n3. Display\n4. Exit\n\nEnter Choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1:cout<<"\n\nEnter Element to Insert : ";
			cin>>ele;
			cout<<"Enter Position to Insert At : ";
			cin>>pos;
			obj.ipos(ele,pos);
			obj.display();
			break;
		case 2:cout<<"\n\nEnter Position to Delete From : ";
			cin>>pos;
			ele=obj.dpos(pos,status);
			if(status==1)
				cout<<"\nElement Deleted : "<<ele<<"\n";
			obj.display();
			break;
		case 3:obj.display();
			break;
		case 4:exit(0);
			break;
		default:cout<<"\nInvalid Selection";
			break;
		}getch();
	}
}

DLIST::DLIST()
{
	p=NULL;
}

void DLIST::ipos(int ele,int pos)
{
	int i=0;
	node *temp,*cur;
	temp=new node;
	temp->item=ele;
	temp->l=NULL;
	temp->r=NULL;
	
	if(pos==0)
	{
		if(p==NULL)
		{
			p=temp;
			return;
		}
		temp->r=p;
		p->l=temp;
		p=temp;
		return;
	}
	
	if((p==NULL)&&pos!=0)
	{
		return;
	}

	cur=p;
	while(cur->r!=NULL)
	{
		cur=cur->r;
		i++;
		if(i==pos)
		{
			temp->l=cur->l;
			temp->r=cur;
			cur->l->r=temp;
			cur->l=temp;
			return;
		}
	}

	i++;
	if(i==pos)
	{
		temp->l=cur;
		cur->r=temp;
		return;
	}

	cout<<"\nInvalid Position\n";
}

int DLIST::dpos(int pos,int &status)
{
	node *cur=p;
	int del,i=0;
	if(p==NULL)
	{
		status=0;
		return NULL;
	}
	if(pos==0)
	{
		del=p->item;
		p=p->r;
		delete cur;
		status=1;
		return del;
	}

	while(cur->r!=NULL)
	{
		cur=cur->r;
		i++;
		if((i==pos)&&(cur->r!=NULL))
		{
			del=cur->item;
			cur->l->r=cur->r;
			cur->r->l=cur->l;
			delete cur;
			status=1;
			return del;
		}
	}

	if(i==pos)
	{
		del=cur->item;
		cur->l->r=NULL;
		delete cur;
		status=1;
		return del;
	}

	cout<<"\nInvalid Position\n";
	status=0;
}

void DLIST::display()
{
	node *r;
	r=p;
	cout<<"\nCurrent List Status : ";
	if(r==NULL)
	{
		cout<<"List Is Empty";
		return;
	}
	while(r!=NULL)
	{
		cout<<r->item<<" ";
		r=r->r;
	}
	cout<<"\n";
}

DLIST::~DLIST()
{
	node *q;
	if(p==NULL)
		return;
	while(p!=NULL)
	{
		q=p->r;
		delete p;
		p=q;
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