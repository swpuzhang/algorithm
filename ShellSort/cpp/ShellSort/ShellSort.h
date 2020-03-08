#pragma once
#include <iterator>
template <class InIt>
void Insert(InIt itLow, InIt curIt, int inc)
{
	
	int inserted = *curIt;
	
	for (;  curIt  > itLow + inc && inserted < *(curIt - inc); curIt -= inc)
	{
		*curIt = *(curIt - inc);
		
	}
	*curIt = inserted;
}

template <class InIt>
void ShellSort( InIt itLow,  InIt itHigh)
{

	for (int inc = std::distance(itLow, itHigh) / 2; inc > 0; inc /= 2)
	{
		for (InIt curIt = itLow + inc; curIt != itHigh; ++curIt)
		{
			Insert(itLow, curIt, inc);
		}
		
	}
}