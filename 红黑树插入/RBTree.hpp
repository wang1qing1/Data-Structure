#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;

enum color
{
	red,
	block,
};

template<class K,class V>
struct RBTreeNode
{
	pair<K,V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	color _col;
		RBTreeNode(const pair<K, V> kv)
		:_kv(kv),
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_col(red)

	{

	}
};

template<class K,class V>
class RBTree
{
public:
	typedef RBTreeNode<K, V> Node;
	RBTree()
	{
	}

	Insert(const pair<K, V> kv)
	{
		//���������������ĸ��ڵ㣬���ڵ�һ���Ǻ�ɫ��
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = block;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (kv.first > parent->_kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		//��ʼ����Ƿ�Ϊά�ֺ��������
		//1. ���ڵ��Ǻ�ɫ��
		//3. ���һ���ڵ��Ǻ�ɫ�ģ��������������ӽ���Ǻ�ɫ��
		//4. ����ÿ����㣬�Ӹý�㵽�����к��Ҷ���ļ�·���ϣ���������ͬ��Ŀ�ĺ�ɫ���

		//1.�����˫�׽ڵ����ɫ�Ǻ�ɫ��û��Υ��������κ����ʣ�����Ҫ����
		//2.�����²���ڵ��˫�׽ڵ���ɫΪ��ɫʱ����Υ��������������������һ��ĺ�ɫ�ڵ�
		//curΪ��ǰ�ڵ㣬pΪ���ڵ㣬gΪ�游�ڵ㣬uΪ����ڵ�
		while (parent && parent->_col == red)
		{
			Node* grandpar = parent->_parent;
			if (parent == grandpar->_left)
			{

				Node* uncle = grandpar->_right;
				//       g
				//   p        u(red)
				//c(��ɫ)
				if (uncle && uncle->_kv == red)//uncle������Ϊ��
				{
					parent->_col = block;
					uncle->_col = block;
					grandpar->_col = red;
					//�������ϸ���
					cur = grandpar;
					parent = cur->_parent;
				}
				//       g
				//   p        u(block)
				//c(�ұߵ���)
				else //uncle�����ڻ��ߴ���Ϊ��
				{
					if (cur == parent->_left)
					{
						RotateR(grandpar);
						parent->_col = block;
						grandpar->_col = red;
					}
					//        g
					//   p        u(block)
					//      c(����˫��ת)
					else
					{
						RotateL(parent);
						RotateR(grandpar);
						cur->_col = block;
						grandpar->_col = red;
					}
					break;
				}
			}
			else
			{
				//        g
				//(red)u        p
				//                   c(��ɫ)
				Node* uncle = grandpar->_left;
				if (uncle && uncle->_kv == red)
				{
					parent->_col = block;
					uncle->_col = block;
					grandpar->_col = red;
					//�������ϸ���
					cur = grandpar;
					parent = cur->_parent;
				}
				else//uncle�����ڻ��ߴ���Ϊ��
				{
					//           g
					//(block)u        p
					//                   c(����)
					if (cur == parent->_right)
					{
						RotateL(grandpar);
						parent->_col = block;
						grandpar->_col = red;
					}
					//           g
					//(block)u        p
					//            c(����)
					else
					{
						RotateR(parent);
						RotateL(grandpar);
						cur->_col = block;
						grandpar->_col = red;
					}
					break;
				}
			}
		}
		//��֤������Ǻ�ɫ��
		_root->_col = block;
	}
private:
	void RotateL(Node* root)
	{
		;
	}
	void RotateR(Node* root)
	{
		;
	}
private:
	Node* _root;
};