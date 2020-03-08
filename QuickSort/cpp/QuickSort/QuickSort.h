#pragma once
#include <iterator>
void QuickSort(size_t low, size_t high, std::vector<int>& data)
{
	if (data.empty() || data.size() == 1 || low >= high)
	{
		return;
	}
	int base = data[low];
	size_t lowTemp = low;
	size_t highTemp = high;
	while (lowTemp < highTemp)
	{
		while (data[highTemp] >= base&& highTemp > lowTemp)
		{
			--highTemp;
		}
		while (data[lowTemp] <= base&& highTemp > lowTemp)
		{
			++lowTemp;
		}
		if (lowTemp < highTemp)
		{
			std::swap(data[highTemp], data[lowTemp]);
		}
	}
	data[low] = data[lowTemp];
	data[lowTemp] = base;
	if (lowTemp == low)
	{
		QuickSort(lowTemp + 1, high, data);
	}
	else if (lowTemp == high)
	{
		QuickSort(low, lowTemp - 1, data);
	}
	else
	{
		QuickSort(low, lowTemp - 1, data);
		QuickSort(lowTemp + 1, high, data);
	}
	
}