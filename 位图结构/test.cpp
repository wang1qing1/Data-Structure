#include"BiteSet.hpp"

void test1()
{
	ikun::biteset<100> bitemap;
	bitemap.set(5);
	bitemap.set(13);
	bitemap.set(10);

	cout << bitemap.test(13) << endl;
	cout << bitemap.test(15) << endl;
}

void test2()
{
	ikun::TwoBiteSet<100> b;
	int arr[] = { 1,12,12,3,4,5,6,7,89,5,3 };
	for (auto e : arr)
	{
		b.set(e);
	}
	cout << b.test(1) << endl;
	cout << b.test(12) << endl;
	cout << b.test(4) << endl;

}
int main()
{
	
	test2();
		


	return 0;
}