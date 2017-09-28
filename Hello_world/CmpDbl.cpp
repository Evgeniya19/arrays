#include "stdafx.h"
#include "cmpdbl.h"

bool cmp_double(const void *a, const void* b)
{
	return (*(static_cast<const double*>(a))) < (*(static_cast<const double*>(b)));
}