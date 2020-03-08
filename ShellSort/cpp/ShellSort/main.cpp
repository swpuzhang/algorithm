#include <vector>
#include <iostream>
#include <algorithm>
#include "ShellSort.h"

int main()
{
	std::vector<int> v = {1, 2, 5, 4, 2, 3};
	auto it = v.end();
	int i = std::distance(v.begin(), it);
	ShellSort(v.begin(), v.end());
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ","));
	return 0;
}