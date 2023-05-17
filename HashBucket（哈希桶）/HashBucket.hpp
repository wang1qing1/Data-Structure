#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

namespace ytt
{

	template<class K, class V>
	struct HashNode
	{
		typedef HashNode<K, V> Node;
		pair<K, V> _date;
		Node* next;

		HashNode(const pair<K, V>& kv)
			:_date(kv),
			next(nullptr)
		{
		}

	};

	template<class K, class V>
	class HashBucket
	{
	public:
		typedef HashBucket<K, V> Hash;
		typedef HashNode<K, V> Node;

		bool Erase(const K& key)
		{
			Node* cur = Find(key);
			if (cur==nullptr)
			{
				return false;
			}
			Node* prev = nullptr;
			Node* head = _table[cur->_date.first % _table.size()];
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
				_table[cur->_date.first % _table.size()] = cur->next;
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
			int hashi = key % _table.size();
			Node* cur = _table[hashi];
			while (cur)
			{
				if (cur->_date.first == key)
				{
					return cur;
				}
				cur = cur->next;
			}
			return nullptr;
		}

		bool Insert(const pair<K, V>& kv)
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
						int hashi = cur->_date.first % newhash._table.size();
						Node* nextnode = cur->next;
						//头插入新表
						cur->next = newhash._table[hashi];
						newhash._table[hashi] = cur;
						cur = nextnode;

						newhash._n++;
					}
				}
				swap(*this,newhash);
				int a = 10;
			}

			int hashi = kv.first % _table.size();
			Node* tail= _table[hashi];
			Node* cur = _table[hashi];
			while (cur)
			{
				if (cur->_date.first == kv.first)
				{
					return false;
				}
				tail = cur;
				cur = cur->next;
			}
			Node* newnode = new Node(kv);
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
