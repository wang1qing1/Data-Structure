#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;


namespace ikun
{
	//海量数据(整形数据)查找是否在不在的问题
	template<size_t N>
	class biteset
	{
	public:
		biteset()
		{
			_bites.resize(N / 8 + 1);
		}
		//插入数据位图
		void  set(int num)
		{
			size_t i = num / 8;
			size_t j = num % 8;
			_bites[i] |= (1 << j);
		}
		//删除数据位图
		void erase(int num)
		{
			size_t i = num / 8;
			size_t j = num % 8;
			_bites[i] &= ~(1 << j);
		}
		//查找数据位图
		bool test(int num)
		{
			size_t i = num / 8;
			size_t j = num % 8;
			return _bites[i] & (1 << j);
		}

	private:
		vector<char> _bites;
	};

	template<size_t N>
	class TwoBiteSet
	{
		//可以查找出现一次，两次等多次的整形数据
	public:
		TwoBiteSet()
		{
		}

		void set(int num)
		{
			if (_bites1.test(num) == false && _bites2.test(num)== false)//00，代表目前一次也没有出现过，00->01
			{
				_bites2.set(num);
			}
			else if (_bites1.test(num) == false && _bites2.test(num) == true)//01，代表目前只出现过一次，01->10
			{
				_bites1.set(num);
				_bites2.erase(num);
			}
			else//10 11,
			{
				//不做处理
			}
		}

		//查找只出现一次的数。
		bool test(int num)
		{
			if (_bites2.test(num))
			{
				return true;
			}
			return false;
		}

	private:
		biteset<N> _bites1;
		biteset<N> _bites2;

	};

	
}