#include <vector>
#include <iostream>
#include <algorithm>
#include "QuickSort.h"

int main()
{
	std::vector<int> v = {1, 2, 5, 4, 2, 3};
	QuickSort(0, v.size() - 1, v);
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ","));
	return 0;
}