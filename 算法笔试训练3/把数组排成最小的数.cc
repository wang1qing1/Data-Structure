#include <string>
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param numbers int����vector
     * @return string�ַ���
     */
     //���������˼�룬���������ʹ�� [a,b,c]->abc��С(abcƴ����)
     //����[a,b]->ab,[b,a]->ba,��֤ab<ba.
     //Ȼ�������[ab,c]->abc,[c,ab]->cab,ʹ��abc<cba
     //��ô��Ȼʹ�ã�[a,b,c,d]����ĳ��˳�򡣾���ab<ba
    static bool com(int num1, int num2)
    {
        string x = to_string(num1);
        string y = to_string(num2);
        string xy = x + y;
        string yx = y + x;
        return xy < yx;

    }
    string PrintMinNumber(vector<int>& numbers) {
        //
        sort(numbers.begin(), numbers.end(), com);
        string ret = "";
        for (int i = 0; i < numbers.size(); i++)
        {
            ret += to_string(numbers[i]);
        }
        return ret;
    }
};