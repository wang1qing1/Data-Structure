#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
//哈希表-----线性探测
namespace ikun
{
	enum Stat
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashNode
	{
		HashNode(pair<K, V> kv)
			:_date(kv),
			_condi(EMPTY)
		{
		}
		HashNode()
			:_date(pair<K,V>(0,0)),
			_condi(EMPTY)
		{
		}
		pair<K, V> _date;
		Stat _condi;
	};

	template<class K, class V>
	class Hash
	{
	public:
		typedef HashNode<K, V> Node;

		Node* Find(const K key)
		{
			//当没有一个数据时
			if (_n == 0)
			{
				return nullptr;
			}
			int hashi = key % _hash.size();
			int i = 1;
			int index = hashi;
			//在线性探测的路上，不可能存在EMPTY，当遇到EMPTY也就是没找到。
			while (_hash[index]._condi != EMPTY)
			{
				//在进行检测查询时：
				//1.该节点是否存在
				//2.该节点的值是否是为key
				if (_hash[index]._condi==EXIST&&_hash[index]._date.first == key)
				{
					return &_hash[index];
				}
				index = hashi + i;
				index %= _hash.size();
				//找了一圈,没找到
				if (index == hashi)
				{
					return nullptr;
				}
				i++;
			}
			return nullptr;
		}

		bool Erase(const K key)
		{
			Node* erase_node = Find(key);
			if (erase_node)
			{
				erase_node->_condi = DELETE;
				return true;
			}
			return false;
		}

		void Order()
		{
			for (auto& e : _hash)
			{
				if (e._condi == EXIST)
				{
					cout << e._date.first << ":" << e._date.second << endl;
				}
			}
		}

		bool Insert(pair<K, V> kv)
		{
			//每次插入，首先检查是否需要扩容,负载因子0.7
			//1.如果是第一次插入数据，vector中还没有数据防止除0
			//2.当数据个树，达到size的70%时，开始给表扩容，
			//3.扩容时需要将数据从新插入新的表中
			if (_hash.size() == 0 || _n * 10 / _hash.size() >= 7)
			{
				int newsize = _hash.size() == 0 ? 10 : _hash.size() * 2;
				//1.我们采用，创建一个新的Hash对象，将size扩大，
				//2.将旧的Hash中的数据全部插入到新的Hash中
				//3.最后将新的Hash与旧的Hash交换。
				Hash<K, V> new_hash;
				new_hash._hash.resize(newsize);
				for (auto& e : _hash)
				{
					if (e._condi == EXIST)
					{
						new_hash.Insert(e._date);
					}
				}
				swap(new_hash, *this);
			}
			//开始插入哈希
			//1.求出下标
			int hashi = kv.first % _hash.size();
			int i = 1;
			int index = hashi;
			//线性探测
			while (_hash[index]._condi == EXIST)
			{
				//如果值已经存在直接退出，返回false
				if (_hash[index]._date.first == kv.first)
				{
					return false;
				}
				index = hashi + i;
				index %= _hash.size();
				i++;
			}
			//插入位置
			_hash[index] = Node(kv);
			//修改状态
			_hash[index]._condi = EXIST;
			//存储个数+1
			_n++;
			return true;

		}

	private:
		vector<Node> _hash;
		size_t _n = 0;
	};

}
