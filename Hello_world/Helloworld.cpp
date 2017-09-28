// Helloworld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "cmpint.h"


bool cmp_double(const void *a, const void* b)
{
	return (*(static_cast<const double*>(a))) < (*(static_cast<const double*>(b)));
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


void sort5(void* start, size_t n, size_t type, bool (*compare)(const void*,const void*))
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
	
	int arrInt[] = { 5,-8,3,9081,-0,0,5 };

	size_t sizeInt = sizeof(arrInt[0]);
	size_t arrIntLenght = sizeof(arrInt) / sizeInt;
	

	sort5(arrInt, arrIntLenght, sizeInt, cmp_int);

	std::cout << "After sort(int)" << std::endl;
	for (int i = 0; i < arrIntLenght; i++)
	{		
		std::cout << arrInt[i]<<"\n";
	}

	double arrDouble[] = { 5,7,45,0,3,23, 2.2, -7.65 };
	size_t sizeDouble = sizeof(arrDouble[0]);
	size_t arrDoubleLenght = sizeof(arrDouble) / sizeDouble;
	

	sort5(arrDouble, arrDoubleLenght, sizeDouble, cmp_double);

	std::cout << "After sort(double)" << std::endl;
	for (int i = 0; i < arrDoubleLenght; i++)
	{
		std::cout << arrDouble[i] << "\n ";
	}

		
    return 0;
}





