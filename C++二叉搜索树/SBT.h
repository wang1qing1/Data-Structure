#pragma once
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

template<class K>
class SBTreeNode
{
public:
	SBTreeNode(K key)
		:_key(key),
		_left(nullptr),
		_right(nullptr)
	{
	}
	SBTreeNode* _left;
	SBTreeNode* _right;
	K _key;
};

template<class K>
class SerchBinaryTree
{

public:
	typedef SBTreeNode<K> Node;
	//²åÈë
	bool Insert(K key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		if (parent->_key < key)
		{
			parent->_right = new Node(key);
		}
		else
		{
			parent->_left = new Node(key);
		}
		return true;
	}
	//ÖÐÐò±éÀú
	void MidOrder()
	{
		_MidOrder(_root);
		return;
	}

	//É¾³ý
	bool Erase(K key)
	{
		
	}
private:
	Node* _root=nullptr;
	void _MidOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_MidOrder(root->_left);
		cout << root->_key << " ";
		_MidOrder(root->_right);
	}
};



