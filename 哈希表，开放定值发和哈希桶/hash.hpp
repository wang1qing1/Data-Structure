#pragma once
#include<vector>
#include<iostream>

using namespace std;

namespace HashOpenAdress
{
	enum State
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashDate
	{
		HashDate()
		{
		}
		HashDate(pair<K,V> kv)
			:_kv(kv)
		{}

		pair<K, V> _kv;
		State state = EMPTY;
	};

	template<class K, class V>
	class HashTable
	{
		typedef HashDate<K, V> Date;
	public:
		bool insert(pair<K, V> kv)
		{
			//如果插入的值已经存在
			if (find(kv.first).second)
			{
				return false;
			}

			//扩容
			//负载因子为0.7
			if (_sh.size() == 0 || _n * 10 / _sh.size() == 7)
			{
				//确定新的容量
				int newsize = _sh.size() == 0 ? 10 : _sh.size() * 2;
				//每一次扩容都要重新插入数据
				HashTable<K, V> newHash;
				newHash._sh.resize(newsize);
				for (auto e : _sh)
				{
					newHash.insert(e._kv);
				}
				_sh.swap(newHash._sh);
			}

			//开放定值法，线性探测解决冲突
			int hashi = kv.first % _sh.size();
			int i = 1; int hashn = hashi;
			while (_sh[hashn].state == EXIST)
			{
				hashn = hashi + i;
				hashn %= _sh.size();
				i++;
			}
			_sh[hashn] = Date(kv);
			_sh[hashn].state = EXIST;
			_n++;
			return true;
		}

		bool erase(const K& key)
		{
			pair<int, bool> retfind = find(key);
			if (!retfind.second)
			{
				return false;
			}
			_sh[retfind.first].state = DELETE;
			return true;
		}

		pair<int,bool> find(const K& key)
		{
			if (_sh.empty())
			{
				return pair<int, bool>(-1, false);
			}
			size_t hashi = key % _sh.size();
			int i = 1; int hashn = hashi;
			while (_sh[hashn].state!=EMPTY)
			{
				if (_sh[hashn].state == EXIST && _sh[hashn]._kv.first == key)
				{
					return pair<int,bool>(hashn,true);
				}
				hashn = hashi + i;
				hashn %= _sh.size();
				i++;
				if (hashn == hashi)
				{
					return pair<int, bool>(-1, false);
				}
			}
			return pair<int, bool>(-1, false);
		}

	private:
		vector<Date> _sh; //数据存储
		size_t _n = 0;       //存储数据的个数
	};
}


namespace HashBucket
{
	template<class K, class V>
	struct HashDate
	{
		HashDate(pair<K, V> kv)
			:_kv(kv),
			_next(nullptr)
		{}

		pair<K, V> _kv;
		HashDate* _next;
	};

	template<class K,class V>
	class Hashbucket
	{
		typedef HashDate<K, V> Date;
		typedef pair<K, V> KV;
	public:

		bool insert(KV kv)
		{
			//如果待插入的数据已经存在
			if ( find(kv.first))
			{
				return false;
			}

			//扩容
			if (_n == _table.size())
			{
				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				vector<Date*> newtable;
				newtable.resize(newsize);
				for (auto& cur : _table)
				{
					while (cur)
					{
						size_t hashi = cur->_kv.first % newtable.size();
						Date* next = cur->_next;
						cur->_next = newtable[hashi];
						newtable[hashi] = cur;
						cur = next;
					}
				}
				_table.swap(newtable);
			}

			//插入
			size_t hashi = kv.first % _table.size();
			Date* newNode = new Date(kv);
			newNode->_next = _table[hashi];
			_table[hashi] = newNode;
			_n++;
		}

		Date* find(const K& key)
		{
			if (_table.empty())
			{
				return nullptr;
			}
			size_t hashi = key % _table.size();
			Date* cur = _table[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}

		bool erase(const K& key)
		{
			if (!find(key))
			{
				return false;
			}
			size_t hashi = key % _table.size();
			Date* cur = _table[hashi];
			Date* prov = nullptr;

			while (cur)
			{
				if (cur->_kv.first == key)
				{
					//删除
					if (prov == nullptr)
					{
						_table[hashi] = cur->_next;	
					}
					else
					{
						prov->_next = cur->_next;
					}
					delete cur;

					return true;
				}
				else
				{
					prov = cur;
					cur = cur->_next;
				}
			}
		}
		~Hashbucket()
		{
			for (auto& cur : _table)
			{
				while (cur)
				{
					Date* next = cur->_next;
					delete cur;
					cur = next;
				}
				cur = nullptr;
			}
		}

	private:
		vector<Date*> _table;
		size_t _n = 0;
	};



}