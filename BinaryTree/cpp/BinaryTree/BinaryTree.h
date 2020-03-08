#pragma once
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>
#include <assert.h>
template <typename T>
struct TreeNode
{
	TreeNode(const T& data, TreeNode* left, TreeNode* right) :
		_data(data),
		_left(left),
		_right(right),
		_parent(nullptr)
	{

	}
	T _data;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode* _parent;
};

template<typename T>
class BinaryTree
{
private:
	TreeNode<T>* _root;


public:
	BinaryTree() : _root(nullptr) {}
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
			node = new TreeNode<T>(data, nullptr, nullptr);
			return node;
		}
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
		return node;
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
		TreeNode<T>* removeNode = Find(_root, data);
		if (removeNode == nullptr)
		{
			return;
		}

		/*
		该节点有两个孩子, 找到该节点的后继节点(比该节点大的最小值), 由于后继节点肯定没有左子树, 后面的删除逻辑统一处理
		*/
		if (removeNode->_left != nullptr && removeNode->_right != nullptr)
		{
			TreeNode<T>* nextNode = GetNext(removeNode);
			assert(nextNode != nullptr);
			removeNode->_data = nextNode->_data;
			removeNode = nextNode;
		}

		/*
		无孩子和只有1个孩子节点的情况, 直接删除节点, 如果该节点是左孩子, 父节点的左孩子设置为该节点的一个孩子,
		如果该节点是右孩子, 父节点的右孩子设置为该节点的一个孩子
		*/

		TreeNode<T>* child = removeNode->_left ? removeNode->_left : removeNode->_right;
		if (removeNode->_parent != nullptr)
		{
			if (removeNode->_parent->_left == removeNode)
			{
				removeNode->_parent->_left = child;
			}
			else if (removeNode->_parent->_right == removeNode)
			{
				removeNode->_parent->_right = child;
			}
			if (child != nullptr)
			{
				child->_parent = removeNode->_parent;
			}
			
		}
		else
		{
			_root = child;
			if (child != nullptr)
			{
				child->_parent = removeNode->_parent;
			}
		}
		delete removeNode;
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
