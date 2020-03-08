#pragma once
#include <iterator>
template <class InIt, class Ty>
std::pair<bool, InIt> BinarySearch( InIt itLow,  InIt itHight, const Ty& val)
{
	while (itLow != itHight)
	{
		InIt itMid = itLow;
		std::advance(itMid, std::distance(itLow, itHight) / 2);
		Ty guess = *itMid;
		if (guess == val)
		{
			return  { true, itMid };
		}
		else if (guess < val)
		{
			itLow = itMid + 1;
		}
		else
		{
			itHight = itMid - 1;
		}
	}
	return { false, itHight };
}