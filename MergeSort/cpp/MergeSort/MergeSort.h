#pragma once
#include <iterator>
#include <vector>
static void Merge(size_t low, size_t middle, size_t high, std::vector<int>& data)
{
	std::vector<int> v;
	size_t lowIndex = low;
	size_t highIndex = middle + 1;
	while (lowIndex <= middle && highIndex <= high)
	{
		if (data[lowIndex] <= data[highIndex])
		{
			v.push_back(data[lowIndex]);
			++lowIndex;
		}
		else
		{
			v.push_back(data[highIndex]);
			++highIndex;
		}
	}
	while (lowIndex <= middle)
	{
		v.push_back(data[lowIndex]);
		++lowIndex;
	}
	while (highIndex <= high)
	{
		v.push_back(data[highIndex]);
		++highIndex;
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		data[low + i] = v[i];
	}
}

static void MergeSort(size_t low, size_t high, std::vector<int>& data)
{
	if (data.empty() || data.size() == 1 || low >= high)
	{
		return;
	}
	size_t mid = (low + high) / 2;
	MergeSort(low, mid, data);
	MergeSort(mid + 1, high, data);
	Merge(low, mid, high, data);
}