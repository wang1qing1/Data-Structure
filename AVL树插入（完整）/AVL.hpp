#pragma once
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cassert>
using namespace std;

template<class K,class V>
struct AVLNode
{
	AVLNode(pair<K, V> kv)
		:_kv(kv),_left(nullptr),_right(nullptr),_parent(nullptr),_bf(0)
	{
	}
	pair<K, V> _kv;
	AVLNode<K, V>* _left;
	AVLNode<K, V>* _right;
	AVLNode<K, V>* _parent;
	int _bf;
};

template<class K,class V>
class AVLTree
{
public:
	typedef AVLNode<K, V> Node;
	typedef pair<K, V> Type_Val;
	AVLTree()
		:_root(nullptr)
	{
	}

	bool insert(const Type_Val& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kv > cur->_kv)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kv < cur->_kv)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		//找到了位置，进行插入
		Node*tmp= new Node(kv);
		if (kv > parent->_kv)
		{
			parent->_right = tmp;
			tmp->_parent = parent;
		}
		else
		{
			parent->_left = tmp;
			tmp->_parent = parent;
		}
		
		Node* tmppar = tmp->_parent;
		while (tmppar)
		{
			//插入以后，更新平衡因子
			if (tmp == tmppar->_left)
			{
				tmppar->_bf--;
			}
			else
			{
				tmppar->_bf++;
			}
			//查看平衡因子,是否调整或者继续向上调整
			if (tmppar->_bf == -1 || tmppar->_bf == 1)
			{
				tmp = tmp->_parent;
				tmppar = tmppar->_parent;
			}
			else if (tmppar->_bf == 0)
			{
				//已经平衡
				break;
			}
			else if (tmppar->_bf == 2|| tmppar->_bf == -2)
			{
				//出现不平衡,开始调整
				if (tmppar->_bf == -2 && tmppar->_left->_bf == -1)
				{
					RotateR(tmppar);
				}
				else if (tmppar->_bf == 2 && tmppar->_right->_bf == 1)
				{
					RotateL(tmppar);
				}
				else if (tmppar->_bf == -2 && tmppar->_left->_bf == 1)
 				{
					RotateLR(tmppar);
				}
				else if (tmppar->_bf == 2 && tmppar->_right->_bf == -1)
				{
					RotateRL(tmppar);
				}
				else
				{
					assert(false);
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}
	int GetTall()
	{
		return _GetTall(_root);
	}
	bool isAVLTree()
	{
		return _isAVLTree(_root);
	}
	int _GetTall(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int LH = _GetTall(root->_left);
		int RH = _GetTall(root->_right);
		return (LH>RH?LH:RH) + 1;
	}
	bool _isAVLTree(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		int LH = _GetTall(root->_left);
		int RH = _GetTall(root->_right);
		int tmp = LH - RH;
		if (tmp < 0)tmp = -tmp;
		if (tmp >= 2||!_isAVLTree(root->_left)||!_isAVLTree(root->_right))
		{
			return false;
		}
		return true;
	}
	void Midorder()
	{
		_Midorder(_root);
	}
private:
	void _Midorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Midorder(root->_left);
		printf("<kv:%d,bf:%d>\n", root->_kv, root->_bf);
		_Midorder(root->_right);
	}
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		RotateR(parent->_right);
		RotateL(parent);

		if (subRL->_bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (subRL->_bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (subRL->_bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	//左右双旋
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		RotateL(parent->_left);
		RotateR(parent);
		if (subLR->_bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (subLR->_bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (subLR->_bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
			
	}

	//右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		//调整结点，调整父亲
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		Node* pparent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		//查看是否是根节点
		if (pparent == nullptr)
		{
			_root = subL;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = subL;
			}
			else
			{
				pparent->_right = subL;
			}
		}
		subL->_parent = pparent;
		//调整平衡因子
		subL->_bf = parent->_bf = 0;
	}
	//左单旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		Node* pparent = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (pparent == nullptr)
		{
			_root = subR;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = subR;
			}
			else
			{
				pparent->_right = subR;
			}
		}
		subR->_parent = pparent;
		subR->_bf = parent->_bf = 0;
	}
	Node* _root;
};


