#pragma once
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>
#include <assert.h>
template <typename T>
struct TreeNode
{
	TreeNode(const T& data) :
		_data(data),
		_height(0),
		_balance(0),
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr)

	{

	}
	T _data;
	int  _height;
	int _balance;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode* _parent;
};

template<typename T>
class AVLTree
{
private:
	TreeNode<T>* _root;


public:
	AVLTree() : _root(nullptr) {}
	void MideOrderOneNode(TreeNode<T>* node, const std::function<void(T)>& fun)
	{
		if (node == nullptr)
		{
			return;
		}
		MideOrderOneNode(node->_left, fun);
		fun(node->_data);
		MideOrderOneNode(node->_right, fun);
	}

	void MideOrder(const std::function<void(T)>& fun)
	{
		MideOrderOneNode(_root, fun);
	}
	
	void PreOrderOneNode(TreeNode<T>* node, const std::function<void(T)>& fun)
	{
		if (node == nullptr)
		{
			return;
		}
		fun(node->_data);
		PreOrderOneNode(node->_left, fun);
		PreOrderOneNode(node->_right, fun);
	}

	void PreOrder(const std::function<void(T)>& fun)
	{
		PreOrderOneNode(_root, fun);
	}

	void BackOrderOneNode(TreeNode<T>* node, const std::function<void(T)>& fun)
	{
		if (node == nullptr)
		{
			return;
		}
		BackOrderOneNode(node->_left, fun);
		BackOrderOneNode(node->_right, fun);
		fun(node->_data);
		
	}

	void BackOrder(const std::function<void(T)>& fun)
	{
		BackOrderOneNode(_root, fun);
	}

	template<typename Iter>
	void Create(Iter begin, Iter end)
	{
		if (_root != nullptr)
		{
			return;
		}
		for (auto iter = begin; iter != end; iter++)
		{
			_root = Insert(_root, *iter);
		}
	}

	TreeNode<T>* Insert(TreeNode<T>* node, const T& data)
	{
		if (node == nullptr)
		{
			node = new TreeNode<T>(data);
		}
		else
		{
			if (node->_data > data)
			{
				node->_left = Insert(node->_left, data);
				node->_left->_parent = node;
			}
			else if (node->_data < data)
			{
				node->_right = Insert(node->_right, data);
				node->_right->_parent = node;
			}
			else
			{
				return node;
			}
		}
		
		node->_height = CalculateHeight(node);
		node->_balance = CalculateBalance(node);
		node = Balance(node);

		return node;
	}
	TreeNode<T>* RightRotate(TreeNode<T>* node)
	{
		TreeNode<T>* parent = node->_parent;
		TreeNode<T>* leftSon = node->_left;
		TreeNode<T>* leftSonRighSon = node->_left->_right;
		leftSon->_parent = parent;
		if (parent != nullptr)
		{
			if (node == parent->_left)
			{
				parent->_left = leftSon;
			}
			else if (node == parent->_right)
			{
				parent->_right = leftSon;
			}
		}
		leftSon->_right = node;
		node->_parent = leftSon;
		node->_left = leftSonRighSon;
		if (leftSonRighSon != nullptr)
		{
			leftSonRighSon->_parent = node;
		}
		node->_height = CalculateHeight(node);
		node->_balance = CalculateBalance(node);
		leftSon->_height = CalculateHeight(leftSon);
		leftSon->_balance = CalculateBalance(leftSon);
		return leftSon;
	}
	TreeNode<T>* LeftRotate(TreeNode<T>* node)
	{
		TreeNode<T>* parent = node->_parent;
		TreeNode<T>* rightSon = node->_right;
		TreeNode<T>* rightSonLeftSon = rightSon->_left;
		rightSon->_parent = parent;
		if (parent != nullptr)
		{
			if (node == parent->_left)
			{
				parent->_left = rightSon;
			}
			else if (node == parent->_right)
			{
				parent->_right = rightSon;
			}
		}
		rightSon->_left = node;
		node->_parent = rightSon;
		node->_right = rightSonLeftSon;
		if (rightSonLeftSon != nullptr)
		{
			rightSonLeftSon->_parent = node;
		}

		node->_height = CalculateHeight(node);
		node->_balance = CalculateBalance(node);
		rightSon->_height = CalculateHeight(rightSon);
		rightSon->_balance = CalculateBalance(rightSon);
		return rightSon;
	}
	TreeNode<T>* Balance(TreeNode<T>* node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		//左子树深, 右旋
		if (node->_balance >= 2)
		{
			//右子树高, 需要先左旋
			if (node->_left->_balance < 0)
			{
				LeftRotate(node->_left);
			}
			//右旋
			node = RightRotate(node);
		}
		else if (node->_balance <= -2)
		{
			//左子树高, 需要先右旋
			if (node->_right->_balance > 0)
			{
				RightRotate(node->_right);
			}
			//左旋
			node = LeftRotate(node);
		}
		return node;
	}

	int CalculateHeight(TreeNode<T>* node)
	{
		int height = -1;
		if (node->_left != nullptr)
		{
			height = node->_left->_height;
		}
		if (node->_right != nullptr && node->_right->_height > height)
		{
			height = node->_right->_height;
		}
		++height;
		return height;
	}

	int CalculateBalance(TreeNode<T>* node)
	{
		int left = node->_left != nullptr ? node->_left->_height : -1;
		int right = node->_right != nullptr ? node->_right->_height : -1;
		return left - right;
	}

	TreeNode<T>* Find(TreeNode<T>* node, const T& data)
	{
		if (node == nullptr)
		{
			return node;
		}
		if (node->_data == data)
		{
			return node;
		}
		else if (node->_data > data)
		{
			return Find(node->_left, data);
		}
		else
		{
			return Find(node->_right, data);
		}
		return nullptr;
	}
	TreeNode<T>* Find(const T& data)
	{
		return Find(_root, data);
	}
	void RemoveAll(TreeNode<T>* node)
	{
		if (node == nullptr)
		{
			return;
		}
		RemoveAll(node->_left);
		RemoveAll(node->_right);
		delete node;
	}
	void Remove(const T& data)
	{
		_root = Remove(_root, data);
	}
	TreeNode<T>* Remove(TreeNode<T>* node, const T& data)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		if (data < node->_data)
		{
			node = Remove(node->_left, data);
			return Balance(node);
		}
		else if (data > node->_data)
		{
			node = Remove(node->_right, data);
			return Balance(node);
		}
		else
		{
			if (node->_left != nullptr && node->_right != nullptr)
			{
				if (node->_left->_height > node->_right->_height)
				{
					node->_data = GetMaxNode(node->_left)->_data;
					node = Remove(node->_left, node->_data);
				}
				else
				{
					node->_data = GetMinNode(node->_right)->_data;
					node = Remove(node->_right, node->_data);
				}
			}
			else
			{

				TreeNode<T>* child = node->_left ? node->_left : node->_right;
				if (child != nullptr)
				{
					child->_parent = node->_parent;
					*node = *child;
					delete child;
				}
				else
				{
					if (node->_parent)
					{
						if (node->_parent->_left == node)
						{
							node->_parent->_left = nullptr;
						}
						else if (node->_parent->_right == node)
						{
							node->_parent->_right = nullptr;
						}
					}
					
					delete node;
					node = nullptr;
				}
			}
		}
		return node;
	}

	//获得最大节点值
	TreeNode<T>* GetMaxNode(TreeNode<T>* node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		if (node->_right == nullptr)
		{
			return node;
		}
		return GetMaxNode(node->_right);
	}
	//获得最小节点值
	TreeNode<T>* GetMinNode(TreeNode<T>* node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		if (node->_left == nullptr)
		{
			return node;
		}
		return GetMinNode(node->_left);
	}

	//获取后驱节点
	TreeNode<T>* GetNext(TreeNode<T>* node)
	{
		//如果有有右节点
		TreeNode<T>* next;
		if (node->_right != nullptr)
		{
			next = node->_right;
			while (next && next->_left)
			{
				next = next->_left;
			}
			return next;
		}
		//如果没有右节点 判断父节的左孩子是不是该节点
		while (node->_parent)
		{
			if (node->_parent->_left == node)
			{
				return node->_parent;
			}
			node = node->_parent;
		}
		return nullptr;
	}
};
