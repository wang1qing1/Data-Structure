#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

//用于处理字符串做key。
template<class K>
struct StrHash
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

template<>
struct StrHash<string>
{
	size_t operator()(const string& str)
	{
		size_t strnum = 0;
		for (auto e : str)
		{
			strnum += e;
			strnum *= 31;
		}
		return strnum;
	}
};

namespace ytt
{

	

	template<class T>
	struct HashNode
	{
		typedef HashNode<T> Node;
		T _date;
		Node* next;

		HashNode(const T& kv)
			:_date(kv),
			next(nullptr)
		{
		}

	};

	template<class K,class T,class KeyOfT,class StrHash>
	class HashBucket
	{
	public:
		typedef HashBucket<K,T,KeyOfT,StrHash> Hash;
		typedef HashNode<T> Node;
		//friend class StrHash;
		KeyOfT kot;
		StrHash SHash;

		bool Erase(const K& key)
		{
			Node* cur = Find(key);
			if (cur==nullptr)
			{
				return false;
			}
			Node* prev = nullptr;
			Node* head = _table[SHash(kot(cur->_date)) % _table.size()];
			while (head!=cur)
			{
				prev = head;
				head = head->next;
			}
			//中间结点
			if (prev)
			{
				prev->next = cur->next;
			}//头结点
			else
			{
				_table[SHash(kot(cur->_date)) % _table.size()] = cur->next;
			}
			delete cur;
			
			return true;
		}
		~HashBucket()
		{
			for (auto& cur : _table)
			{
				Node* next;
				while (cur)
				{
					next = cur->next;
					delete cur;
					cur = next;
				}
			}
		}
		Node* Find(const K& key)
		{
			if (_n == 0)
			{
				return nullptr;
			}
			int hashi = SHash(key) % _table.size();
			Node* cur = _table[hashi];
			while (cur)
			{
				if (SHash(kot(cur->_date)) == SHash(key))
				{
					return cur;
				}
				cur = cur->next;
			}
			return nullptr;
		}

		bool Insert(const T& kv)
		{
			if (_table.size() == 0 || _n / _table.size() >= 1)
			{
				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				Hash newhash;
				newhash._table.resize(newsize);
				for (auto& cur : _table)
				{
					while (cur)
					{
						auto tmp = kot(cur->_date);
						int hashi = SHash(tmp) % newhash._table.size();
						Node* nextnode = cur->next;
						//头插入新表
						cur->next = newhash._table[hashi];
						newhash._table[hashi] = cur;
						cur = nextnode;

						newhash._n++;
					}
				}
				swap(*this,newhash);//没问题
				//swap(newhash, *this);//出问题
			}

			int hashi = SHash(kot(kv)) % _table.size();
			Node* tail= _table[hashi];
			Node* cur = _table[hashi];
			//尾插新节点
			while (cur)
			{
				//如果已经存在
				if (SHash(kot(cur->_date)) == SHash(kot(kv)))
				{
					return false;
				}
				tail = cur;
				cur = cur->next;
			}
			Node* newnode = new Node(kv);
			//如果是第一个插入的结点
			if (tail == nullptr)
			{
				_table[hashi] = newnode;
			}
			else
			{
				tail->next = newnode;
			}
			_n++;
		}
	private:
		vector<Node*> _table;
		size_t _n = 0;
	};
}
