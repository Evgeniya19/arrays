#include "header2.h"

void sort7(void* start, size_t n, size_t type)
{
	char* pCur = static_cast<char*>(start);

	for (int i = 0; i < (n - 1); i++)
	{
		//cout << i  << " pass" << endl;
		char* pMin = pCur;
		char* pTmp = pCur + type;
		for (int j = i + 1; j < n; j++)
		{

			//cout << *(int*)pTmp <<" " ;
			//if (cmp(pTmp, pMin))
			//if (*pTmp < *pMin)
			if (comp_any_type(pTmp, pMin, type))
				pMin = pTmp;
			pTmp += type;
		}
		rearr(pMin, pCur, type);
		/*
		long double tmp = *pMin;
		*pMin = *pCur;
		*pCur = tmp;
		*/
		//cout_arr(start, n, type);

		pCur += type;
		cout << endl;
	}

}