#include"hash.hpp"


int main()
{
	ikun::Hash<int, int> hash;
	
	hash.Insert(pair<int, int>(2, 2));
	hash.Insert(pair<int, int>(12, 12));
	hash.Insert(pair<int, int>(3, 3));
	hash.Insert(pair<int, int>(13, 13));
	hash.Insert(pair<int, int>(4, 14));
	hash.Insert(pair<int, int>(5, 15));
	hash.Insert(pair<int, int>(6, 16));
	hash.Insert(pair<int, int>(7, 17));
	hash.Insert(pair<int, int>(8, 18));

	//hash.Find(2)->_date.second *= 10;
	//hash.Find(12)->_date.second *= 10;
	//hash.Find(3)->_date.second *= 10;
	//hash.Find(4)->_date.second *= 10;

	hash.Order();
	cout << "----------------------------------------------------" << endl;
	hash.Erase(4);
	hash.Erase(7);
	hash.Erase(5);

	if (hash.Find(4))
	{
		cout << hash.Find(4)->_date.first << ":´æÔÚ" << endl;
	}
	else
	{
		cout << "²»´æÔÚ" << endl;
	}

	//hash.Order();



	return 0;
}