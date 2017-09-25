// Helloworld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "header2.h"
#include "header2.h"

using namespace std;
void sort(int* start, size_t n);
void sort2(int p1[], size_t n);




int main()
{
	/*
	const int* pc;
	int n = 5;
	pc = &n;
	cout << *pc << endl;
	int x = 8;
	pc = &x;
	cout << *pc << endl;
	pc++;
	//(*pc)++;
	cout << *pc << endl;
	//int*p = pc;

	int* const ps = &n;
	cout << *ps << endl;
	*ps = *pc;
	cout << *ps << endl;
	(*ps)++;
	cout << *ps << endl;
	//ps++;
	int *p;
	p = ps;
	p++;
	//ps = p;
	int np = 19;
	p = &np;
	int* const *pro = &p;
	cout << p << endl;
	cout << *p << endl;
	cout << *pro << endl;
	cout << **pro << endl;
	//cout << **pro << endl;

	cout << "Hello, world!" << endl;
	*/
	int arr1[] = { 5,6,3,-8,0,5 };
	size_t n = sizeof(arr1) / sizeof(arr1[0]);
	sort2(arr1, n);

	/*
	int arr[] = { 5,6,3,-8,0,5 };
	size_t n = sizeof(arr) / sizeof(arr[0]);
	sort(arr, n);
	
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
	*/

	_getch();

    return 0;
}
void sort(int* start, size_t n)
{
	cout << "sort(int* start, size_t n)" << endl;
	int* pCur = start;
	for (int i = 0; i < (n - 1); i++)
	{
		int* pMin = pCur;
		int* pTmp = pCur + 1;
		for (int j = i + 1; j < n; j++)
		{
			if (*pTmp < *pMin)
				pMin = pTmp;
			pTmp++;
		}
		int tmp = *pMin;
		*pMin = *pCur;
		*pCur = tmp;

		pCur++;
	}
}

void sort2(int p1[], size_t n)
{
	cout << "sort2" << endl;

	for (int i = 0; i < n - 1; i++)
	{
		int min = i;

		for (int j = i + 1; j < n; j++)
		{
			if (p1[j] < p1[min])
				min = j;
		}

		int buf = p1[min];
		p1[min] = p1[i];
		p1[i] = buf;
	}
	for (int i = 0; i < n; i++)
	{
		cout << p1[i] << endl;
	}

}


