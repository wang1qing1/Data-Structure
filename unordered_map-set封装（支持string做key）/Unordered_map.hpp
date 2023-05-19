#pragma once
#include"HashBucket.hpp"



template<class K, class V,class StrHash = StrHash<K>>
class unordered_map
{
public:
	typedef ytt::HashNode<pair<K, V>> Node;

	struct MapOfKey
	{
		K operator()(const pair<K, V> kv)
		{
			return kv.first;
		}
	};

	bool Insert(const pair<K, V> kv)
	{
		return _hash.Insert(kv);
	}

	Node* Find(const K& key)
	{
		return _hash.Find(key);
	}

	~unordered_map()
	{
		_hash.~HashBucket();
	}
	
private:
	typedef typename ytt::HashBucket<K, pair<K, V>, MapOfKey,StrHash> Hash;
	Hash _hash;
};
