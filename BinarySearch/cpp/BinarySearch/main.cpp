#include <vector>
#include <iostream>
#include <algorithm>
#include "BinarySearch.h"

int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5, 6};
	auto it = v.end();
	int i = std::distance(v.begin(), it);
	auto ret = BinarySearch(v.begin(), v.end(), 5);
	if (ret.first == false)
	{
		std::cout << "5 is not in v\n";
	}
	else
	{
		std::cout << "5 is  in v\n";
	}
	return 0;
}