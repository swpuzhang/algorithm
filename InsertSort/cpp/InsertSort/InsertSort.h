#pragma once
#include <iterator>
template <class InIt>
void Insert(InIt itLow, InIt curIt)
{
	if (curIt == itLow)
	{
		return;
	}
	int inserted = *curIt;
	
	for (;  curIt != itLow && inserted < *(curIt - 1); --curIt)
	{
		*curIt = *(curIt - 1);
	}
	*curIt = inserted;
}

template <class InIt>
void InsertSort( InIt itLow,  InIt itHight)
{
	for (InIt curIt = itLow + 1; curIt != itHight; ++curIt)
	{
		Insert(itLow, curIt);
	}
}