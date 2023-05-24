#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;


namespace ikun
{
	//��������(��������)�����Ƿ��ڲ��ڵ�����
	template<size_t N>
	class biteset
	{
	public:
		biteset()
		{
			_bites.resize(N / 8 + 1);
		}
		//��������λͼ
		void  set(int num)
		{
			size_t i = num / 8;
			size_t j = num % 8;
			_bites[i] |= (1 << j);
		}
		//ɾ������λͼ
		void erase(int num)
		{
			size_t i = num / 8;
			size_t j = num % 8;
			_bites[i] &= ~(1 << j);
		}
		//��������λͼ
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
		//���Բ��ҳ���һ�Σ����εȶ�ε���������
	public:
		TwoBiteSet()
		{
		}

		void set(int num)
		{
			if (_bites1.test(num) == false && _bites2.test(num)== false)//00������Ŀǰһ��Ҳû�г��ֹ���00->01
			{
				_bites2.set(num);
			}
			else if (_bites1.test(num) == false && _bites2.test(num) == true)//01������Ŀǰֻ���ֹ�һ�Σ�01->10
			{
				_bites1.set(num);
				_bites2.erase(num);
			}
			else//10 11,
			{
				//��������
			}
		}

		//����ֻ����һ�ε�����
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