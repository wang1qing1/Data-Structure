#include <string>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return string字符串
     */
     //借助排序的思想，如果我们想使得 [a,b,c]->abc最小(abc拼接数)
     //首先[a,b]->ab,[b,a]->ba,保证ab<ba.
     //然后才能有[ab,c]->abc,[c,ab]->cab,使得abc<cba
     //那么必然使得，[a,b,c,d]存在某种顺序。就是ab<ba
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