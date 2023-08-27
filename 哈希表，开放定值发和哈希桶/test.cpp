
#define _CRT_SECURE_NO_WARNINGS 1
#include"hash.hpp"
using namespace HashOpenAdress;
using namespace HashBucket;


int main()
{
	Hashbucket<int, int> ha;
	int arr[] = { 2,12,3,33,13,5,4,15,55 ,24};
	for (auto e : arr)
	{
		ha.insert(make_pair(e, e));
	}
	ha.insert(make_pair(14, 14));
	ha.erase(55);
	ha.erase(14);
	ha.erase(33);
	ha.erase(13);

	return 0;
}