/**
Lab Program 5 
Templatised Quick Sort
Author SkyKOG
*/

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

template <typename T>
int split ( T a[ ], int lower, int upper );

template <typename T>
void quicksort ( T a[ ], int lower, int upper );

void main( )
{
	int iarr[10] = { 11, 2, 9, 13, 57, 25, 17, 1, 90, 3 } ;
	int i ;

	system ( "cls" ) ;

	cout<<"Templatised Version of Quick Sort : \n";
	cout<<"===================================\n\n";
	cout<<"Integer Array before sorting:\n";

	for ( i = 0 ; i <= 9 ; i++ )
		cout<<iarr[i]<<"\t";

	quicksort ( iarr, 0, 9 ) ;

	cout<<"\n\n";
	cout<<"Integer Array after sorting:\n";

	for ( i = 0 ; i <= 9 ; i++ )
		cout<<iarr[i]<<"\t";

	double darr[10] = { 11.3, 2.6, 9.6, 13.1, 57.98, 25.4, 17.4, 1.8, 90.90, 3.1 } ;
	cout<<"\n\n\nDouble Array before sorting:\n";

	for ( i = 0 ; i <= 9 ; i++ )
		cout<<darr[i]<<"\t";

	quicksort ( darr, 0, 9 ) ;

	cout<<"\n\n";
	cout<<"Double Array after sorting:\n";

	for ( i = 0 ; i <= 9 ; i++ )
		cout<<darr[i]<<"\t";

	getch();
}

template <typename T>int split ( T a[ ], int lower, int upper )
{
	T i,t ;
	int p,q;

	p = lower + 1 ;
	q = upper ;
	i = a[lower] ;

	while ( q >= p )
	{
		while ( a[p] < i )
			p++ ;

		while ( a[q] > i )
			q-- ;

		if ( q > p )
		{
			t = a[p] ;
			a[p] = a[q] ;
			a[q] = t ;
		}
	}

	t = a[lower] ;
	a[lower] = a[q] ;
	a[q] = t ;

	return q ;
}

template <typename T>void quicksort ( T a[ ], int lower, int upper )
{
	int i ;
	if ( upper > lower )
	{
		i = split ( a, lower, upper ) ;
		quicksort ( a, lower, i - 1 ) ;
		quicksort ( a, i + 1, upper ) ;
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