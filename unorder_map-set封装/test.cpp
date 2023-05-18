
#include"Unordered_set.hpp"

//void test_HashTable()
//{
//	ikun::Hash<int, int> hash;
//
//	hash.Insert(pair<int, int>(2, 2));
//	hash.Insert(pair<int, int>(12, 12));
//	hash.Insert(pair<int, int>(3, 3));
//	hash.Insert(pair<int, int>(13, 13));
//	hash.Insert(pair<int, int>(4, 14));
//	hash.Insert(pair<int, int>(5, 15));
//	hash.Insert(pair<int, int>(6, 16));
//	hash.Insert(pair<int, int>(7, 17));
//	hash.Insert(pair<int, int>(8, 18));
//
//	//hash.Find(2)->_date.second *= 10;
//	//hash.Find(12)->_date.second *= 10;
//	//hash.Find(3)->_date.second *= 10;
//	//hash.Find(4)->_date.second *= 10;
//
//	hash.Order();
//	cout << "----------------------------------------------------" << endl;
//	hash.Erase(4);
//	hash.Erase(7);
//	hash.Erase(5);
//
//	if (hash.Find(4))
//	{
//		cout << hash.Find(4)->_date.first << ":存在" << endl;
//	}
//	else
//	{
//		cout << "不存在" << endl;
//	}
//
//	//hash.Order();
//}

//void test_HashBucket()
//{
//
//	int arr[] = {2,4,12,3,13,44,14,45,15,5};
//	ytt::HashBucket<int, int> hash;
//
//	for (auto& e : arr)
//	{
//		hash.Insert(pair<int, int>(e, e));
//	}
//	hash.Insert(pair<int, int>(55, 55));//扩容
//	hash.Insert(pair<int, int>(65, 65));
//
//	hash.Erase(55);
//
//}

void test_unordered_set()
{

	int arr[] = { 2,4,12,3,13,44,14,45,15,5 };
	unordered_set<int> un_set;
	for (auto e : arr)
	{
		un_set.Insert(e);
	}


	cout << un_set.Find(12)->_date << endl;

	un_set.Erase(12);

	if (un_set.Find(12))
	{
		cout << "存在" << endl;
	}
	else
	{
		cout << "不存在" << endl;
	}
}
int main()
{
	
	//test_HashBucket();
	test_unordered_set();
	return 0;
}