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
		�ýڵ�����������, �ҵ��ýڵ�ĺ�̽ڵ�(�ȸýڵ�����Сֵ), ���ں�̽ڵ�϶�û��������, �����ɾ���߼�ͳһ����
		*/
		if (removeNode->_left != nullptr && removeNode->_right != nullptr)
		{
			TreeNode<T>* nextNode = GetNext(removeNode);
			assert(nextNode != nullptr);
			removeNode->_data = nextNode->_data;
			removeNode = nextNode;
		}

		/*
		�޺��Ӻ�ֻ��1�����ӽڵ�����, ֱ��ɾ���ڵ�, ����ýڵ�������, ���ڵ����������Ϊ�ýڵ��һ������,
		����ýڵ����Һ���, ���ڵ���Һ�������Ϊ�ýڵ��һ������
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
	//��ȡ�����ڵ�
	TreeNode<T>* GetNext(TreeNode<T>* node)
	{
		//��������ҽڵ�
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
		//���û���ҽڵ� �жϸ��ڵ������ǲ��Ǹýڵ�
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
