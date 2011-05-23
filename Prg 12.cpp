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
		friend void avg(UGSTUDENT *,int,int);
};

class PGSTUDENT:public STUDENT {

	int sem;
	float fees,stripend;

	public:
		void read();
		void display();
		friend void avg(UGSTUDENT *,int,int);
};


