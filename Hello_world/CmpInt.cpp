#include "stdafx.h"
#include "cmpint.h"

bool cmp_int(const void *a, const void *b)
{
	return (*(static_cast<const int*>(a))) < (*(static_cast<const int*>(b)));
}