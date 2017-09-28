// Helloworld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


bool cmp_int(void *a, void *b)
{
	return (*(static_cast<int*>(a))) < (*(static_cast<int*>(b)));
}

bool cmp_double(void *a,  void*b)
{
	return (*(static_cast<double*>(a))) < (*(static_cast<double*>(b)));
}

void cout_arr(void *p1, size_t n, size_t type)
{
	char* pCur = static_cast<char*>(p1);
	for (int i = 0; i < n; i++)
	{
		std::cout << *(int*)pCur << " ";
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


void sort5(void* start, size_t n, size_t type, bool (*compare)( void*, void*))
{
	char* pCur = static_cast<char*>(start);
	
	for (int i = 0; i < (n - 1); i++)
	{
		char* pMin = pCur;
		char* pTmp = pCur + type;
		for (int j = i + 1; j < n; j++)
		{
			if (compare(pTmp, pMin))
				pMin = pTmp;
			pTmp += type;
		}
		rearr(pMin, pCur, type);		
		pCur +=type;
	}
	
}


int main()
{
	
	int arr_int[] = { 5,-8,3,9081,-0,0,5 };
	size_t n = sizeof(arr_int) / sizeof(arr_int[0]);
	size_t b = sizeof(arr_int[0]);

	sort5(arr_int, n, b, cmp_int);

	std::cout << "After sort(int)" << std::endl;
	for (int i = 0; i < n; i++)
	{		
		std::cout << arr_int[i]<<"\n";
	}

	double arr_d[] = { 5,7,45,0,3,23, 2.2, -7.65 };
	size_t nd = sizeof(arr_d) / sizeof(arr_d[0]);
	size_t bd = sizeof(arr_d[0]);

	sort5(arr_d, nd, bd, cmp_double);

	std::cout << "After sort(double)" << std::endl;
	for (int i = 0; i < nd; i++)
	{
		std::cout << arr_d[i] << "\n ";
	}

		
    return 0;
}





