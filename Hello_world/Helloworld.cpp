// Helloworld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "header2.h"

using namespace std;


bool compare(int a, int b)
{
	return (a) < (b);
}

bool cmp(const void *a, const void *b) {
	return *(int*)a < *(int*)b;
}

void cout_arr(void *p1, size_t n, size_t type)
{
	char* pCur = static_cast<char*>(p1);
	for (int i = 0; i < n; i++)
	{
		cout << *(int*)pCur << " ";
		pCur += type;
	}
}

void rearr(char*a, char*b, size_t type)
{
	for (int i = 0; i < type; i++)
	{
		char buf = *a;
		*a = *b;
		*b = buf;
		a++;
		b++;
	}
}

bool comp_any_type(char*a, char*b, size_t type)
{
	for (int i = 0; i < type; i++)
	{
		if (*a != *b)
			return (*a) < (*b);
		return false;
	}
}

void sort5(void* start, size_t n, size_t type, bool (*compare)(char*, char*, size_t))
{
	char* pCur = static_cast<char*>(start);
	
	for (int i = 0; i < (n - 1); i++)
	{
		cout << i  << " pass" << endl;
		char* pMin = pCur;
		char* pTmp = pCur + type;
		for (int j = i + 1; j < n; j++)
		{
			
			//cout << *(int*)pTmp <<" " ;
			//if (cmp(pTmp, pMin))
			//if (*pTmp < *pMin)
			if (compare(pTmp, pMin, type))
				pMin = pTmp;
			pTmp += type;
		}
		rearr(pMin, pCur, type);
		/*
		long double tmp = *pMin;
		*pMin = *pCur;
		*pCur = tmp;
		*/
		cout_arr(start, n, type);
		
		pCur +=type;
		cout<<endl;
	}
	
}

void sort6(char* start, size_t n, size_t type)
{
	cout << "sort6(int* start, size_t n)" << endl;
	char* pCur = start;

	for (int i = 0; i < (n - 1); i++)
	{
		char* pMin = pCur;
		char* pTmp = pCur + type;
		for (int j = i + 1; j < n; j++)
		{
			if (cmp(pTmp, pMin))
				pMin = pTmp;
			pTmp += type;
		}
		long double tmp = *pMin;
		*pMin = *pCur;
		*pCur = tmp;

		pCur += type;
	}

}

void sort4(int p1[], size_t n)
{
	cout << "sort4" << endl;

	for (int i = 0; i < n - 1; i++)
	{
		int comp = i;

		for (int j = i + 1; j < n; j++)
		{
			if (compare(p1[j],p1[comp]))
			{
					comp = j;
			}
		}

		int buf = p1[comp];
		p1[comp] = p1[i];
		p1[i] = buf;
	}
	for (int i = 0; i < n; i++)
	{
		cout << p1[i] << endl;
	}

}

void sort3(int p1[], size_t n, bool p = true)
{
	cout << "sort2" << endl;

	for (int i = 0; i < n - 1; i++)
	{
		int comp = i;

		for (int j = i + 1; j < n; j++)
		{
			if (p)
			{
				if (p1[j] < p1[comp])
					comp = j;
			}
			else {
				if (p1[j] > p1[comp])
					comp = j;
			}
		}

		int buf = p1[comp];
		p1[comp] = p1[i];
		p1[i] = buf;
	}
	for (int i = 0; i < n; i++)
	{
		cout << p1[i] << endl;
	}

}

int main(int argc, char* argv[], char *envp[])
{
	/*
	for (int i = 0; envp[i] != 0; i++)
	{
		cout << envp[i] << endl;
	}
	
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
	
	int arr1[] = { 5,-8,3,9081,-0,0,5 };

	size_t n = sizeof(arr1) / sizeof(arr1[0]);
	size_t b = sizeof(arr1[0]);
	sort5(arr1, n, b, comp_any_type);
	
	/*
	int arr[] = { 5,6,3,-8,0,5 };
	size_t n = sizeof(arr) / sizeof(arr[0]);
	sort(arr, n);
	*/
	cout << "After sort" << endl;
	for (int i = 0; i < n; i++)
	{		
		cout << arr1[i]<<" ";
	}
		
	_getch();

    return 0;
}
/*
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
*/




