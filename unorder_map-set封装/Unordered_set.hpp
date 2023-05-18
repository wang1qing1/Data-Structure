#pragma once
#include"HashBucket.hpp"



template<class K>
class unordered_set
{
public:
	typedef ytt::HashNode<K> Node;
	struct SetKeyOfT
	{
		K operator()(const K& key)
		{
			return key;
		}
	};

	bool Insert(const K& key)
	{
		return _hash.Insert(key);
	}

	Node* Find(const K& key)
	{
		return _hash.Find(key);
	}

	bool Erase(const K& key)
	{
		return _hash.Erase(key);
	}

	~unordered_set()
	{
		_hash.~HashBucket();

	}
private:
	typedef typename ytt::HashBucket<K,K,SetKeyOfT> Hash;
	Hash _hash;
};
