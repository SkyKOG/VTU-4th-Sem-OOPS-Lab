/**
Lab Program 15 
Infix To Postfix - Expression Class
Author SkyKOG
*/

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

class EXPRESSION {

	int stack[10];
	int top;
	char infix[20],postfix[20];

	public:
		EXPRESSION();
		void accept();
		void push(char);
		char pop();
		int stpri(char ch);
		int inpri(char ch);
		void convert(char [],char[]);
		void display();
};

void main()
{
	system("cls");
	
	EXPRESSION obj;
	
	cout<<"Enter A Valid Infix Expression : ";
	obj.accept();

	cout<<"\nThe Converted Postfix Expression is : ";
	obj.display();
	
	getch();
}

EXPRESSION::EXPRESSION()
{
	top=-1;
	push('#');
}

void EXPRESSION::accept()
{
	cin>>infix;
	convert(infix,postfix);
}


void EXPRESSION::push(char ch)
{
	stack[++top]=ch;
}

char EXPRESSION::pop()
{
	return (stack[top--]);
}

int EXPRESSION::stpri(char ch)
{
	switch(ch)
	{
	case '#':
	case '(':return 0;
	case '+':
	case '-':return 2;
	case '*':
	case '/':return 4;
	case '$':return 5;
	}
}

int EXPRESSION::inpri(char ch)
{
	switch(ch)
	{
	case '+':
	case '-':return 1;
	case '*':
	case '/':return 3;
	case '$':return 6;
	}
}

void EXPRESSION::convert(char inf[20],char post[20])
{
	int i,j=0;
	char ch;
	for(i=0;inf[i];i++)
	{
		ch=inf[i];
		switch(ch)
		{
		case '(':push(ch);
			break;
		case ')':while(stack[top]!='(')
					 post[j++]=pop();
				pop();
				break;
		case '+':
		case '-':
		case '/':
		case '*':
		case '$':while(stpri(stack[top])>inpri(ch))
					 post[j++]=pop();
				push(ch);
				break;
		default:post[j++]=ch;
				break;
		}
	}
	while(stack[top]!='#')
		post[j++]=pop();
	post[j]='\0';
}

void EXPRESSION::display()
{
	cout<<postfix;
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