#include <vector>
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param sum int����
     * @return int����vector<vector<>>
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
            //˫ָ��
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