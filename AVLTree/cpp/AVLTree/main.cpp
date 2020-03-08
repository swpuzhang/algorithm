#include <vector>
#include <iostream>
#include <algorithm>
#include "AVLTree.h"

int main()
{
	std::vector<int> v = {5, 4, 1,  7, 6, 8, 3};
	AVLTree<int> tree;
	tree.Create(v.begin(), v.end());
	tree.MideOrder([](int x) {std::cout << x << std::endl; });
	std::cout << std::endl;
	tree.PreOrder([](int x) {std::cout << x << std::endl; });
	std::cout << std::endl;
	tree.BackOrder([](int x) {std::cout << x << std::endl; });
	std::cout << std::endl;
	tree.Remove(8);
	tree.Find(1);
	/*tree.Remove(1);
	tree.MideOrder([](int x) {std::cout << x << std::endl; });
	std::cout << std::endl;
	tree.Remove(3);
	tree.MideOrder([](int x) {std::cout << x << std::endl; });
	std::cout << std::endl;
	tree.Remove(4);
	tree.MideOrder([](int x) {std::cout << x << std::endl; });
	std::cout << std::endl;
	tree.Remove(5);
	tree.MideOrder([](int x) {std::cout << x << std::endl; });
	std::cout << std::endl;
	tree.Remove(6);
	tree.MideOrder([](int x) {std::cout << x << std::endl; });
	std::cout << std::endl;
	tree.Remove(7);
	tree.MideOrder([](int x) {std::cout << x << std::endl; });
	std::cout << std::endl;
	tree.Remove(8);
	tree.MideOrder([](int x) {std::cout << x << std::endl; });
	std::cout << std::endl;*/
	return 0;
}
