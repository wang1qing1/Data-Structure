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
		//如果插入的整棵树的根节点，根节点一定是黑色的
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

		//开始检查是否为维持红黑树特性
		//1. 根节点是黑色的
		//3. 如果一个节点是红色的，则它的两个孩子结点是黑色的
		//4. 对于每个结点，从该结点到其所有后代叶结点的简单路径上，均包含相同数目的黑色结点

		//1.如果其双亲节点的颜色是黑色，没有违反红黑树任何性质，则不需要调整
		//2.但当新插入节点的双亲节点颜色为红色时，就违反了性质三不能有连在一起的红色节点
		//cur为当前节点，p为父节点，g为祖父节点，u为叔叔节点
		while (parent && parent->_col == red)
		{
			Node* grandpar = parent->_parent;
			if (parent == grandpar->_left)
			{

				Node* uncle = grandpar->_right;
				//       g
				//   p        u(red)
				//c(变色)
				if (uncle && uncle->_kv == red)//uncle存在且为红
				{
					parent->_col = block;
					uncle->_col = block;
					grandpar->_col = red;
					//继续向上更改
					cur = grandpar;
					parent = cur->_parent;
				}
				//       g
				//   p        u(block)
				//c(右边单旋)
				else //uncle不存在或者存在为黑
				{
					if (cur == parent->_left)
					{
						RotateR(grandpar);
						parent->_col = block;
						grandpar->_col = red;
					}
					//        g
					//   p        u(block)
					//      c(左右双旋转)
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
				//                   c(变色)
				Node* uncle = grandpar->_left;
				if (uncle && uncle->_kv == red)
				{
					parent->_col = block;
					uncle->_col = block;
					grandpar->_col = red;
					//继续向上更改
					cur = grandpar;
					parent = cur->_parent;
				}
				else//uncle不存在或者存在为黑
				{
					//           g
					//(block)u        p
					//                   c(左单旋)
					if (cur == parent->_right)
					{
						RotateL(grandpar);
						parent->_col = block;
						grandpar->_col = red;
					}
					//           g
					//(block)u        p
					//            c(左单旋)
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
		//保证根结点是黑色；
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