#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
//��ϣ��-----����̽��
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
			//��û��һ������ʱ
			if (_n == 0)
			{
				return nullptr;
			}
			int hashi = key % _hash.size();
			int i = 1;
			int index = hashi;
			//������̽���·�ϣ������ܴ���EMPTY��������EMPTYҲ����û�ҵ���
			while (_hash[index]._condi != EMPTY)
			{
				//�ڽ��м���ѯʱ��
				//1.�ýڵ��Ƿ����
				//2.�ýڵ��ֵ�Ƿ���Ϊkey
				if (_hash[index]._condi==EXIST&&_hash[index]._date.first == key)
				{
					return &_hash[index];
				}
				index = hashi + i;
				index %= _hash.size();
				//����һȦ,û�ҵ�
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
			//ÿ�β��룬���ȼ���Ƿ���Ҫ����,��������0.7
			//1.����ǵ�һ�β������ݣ�vector�л�û�����ݷ�ֹ��0
			//2.�����ݸ������ﵽsize��70%ʱ����ʼ�������ݣ�
			//3.����ʱ��Ҫ�����ݴ��²����µı���
			if (_hash.size() == 0 || _n * 10 / _hash.size() >= 7)
			{
				int newsize = _hash.size() == 0 ? 10 : _hash.size() * 2;
				//1.���ǲ��ã�����һ���µ�Hash���󣬽�size����
				//2.���ɵ�Hash�е�����ȫ�����뵽�µ�Hash��
				//3.����µ�Hash��ɵ�Hash������
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
			//��ʼ�����ϣ
			//1.����±�
			int hashi = kv.first % _hash.size();
			int i = 1;
			int index = hashi;
			//����̽��
			while (_hash[index]._condi == EXIST)
			{
				//���ֵ�Ѿ�����ֱ���˳�������false
				if (_hash[index]._date.first == kv.first)
				{
					return false;
				}
				index = hashi + i;
				index %= _hash.size();
				i++;
			}
			//����λ��
			_hash[index] = Node(kv);
			//�޸�״̬
			_hash[index]._condi = EXIST;
			//�洢����+1
			_n++;
			return true;

		}

	private:
		vector<Node> _hash;
		size_t _n = 0;
	};

}
