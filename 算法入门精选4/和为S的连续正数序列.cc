#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param sum int整型
     * @return int整型vector<vector<>>
     */
    int Sum_add(int left, int right, vector<int>& v)
    {
        int ret = 0;
        for (int i = left; i <= right; i++)
        {
            v.push_back(i);
            ret += i;
        }
        return ret;
    }
    vector<vector<int> > FindContinuousSequence(int sum) {
        int left = 1;
        int right = 1;
        vector<vector<int>> vv;
        vector<int> v;
        while (right < sum)
        {

            int tmpsum = Sum_add(left, right, v);
            //双指针
            if (tmpsum < sum)
            {
                right++;
            }
            else if (tmpsum > sum)
            {
                left++;
            }
            else
            {
                if (left != right)
                {
                    vv.push_back(v);
                    left++;
                }
            }
            v.clear();
        }
        return vv;
    }
};