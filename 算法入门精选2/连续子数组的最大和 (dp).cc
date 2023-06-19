class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param array int����vector
     * @return int����
     */
    int FindGreatestSumOfSubArray(vector<int>& array) {

        int* dp = new int[array.size()];
        //1.����״̬
        //f(i)��i�±��β��������������еĺ�.
        //2.״̬ת�Ʒ���
        //f(i)=max(f(i-1)+array[i],array[i]);
        //f(i)ֻ����������Դ����һ����f(i-1)+array[i],�ڶ����Ǿ���array[i].
        //3.��ʼ״̬
        //f(0)=array[0];
        dp[0] = array[0];
        int max_val = dp[0];
        for (int i = 1; i < array.size(); i++)
        {
            dp[i] = max(dp[i - 1] + array[i], array[i]);
            if (max_val < dp[i])
            {
                max_val = dp[i];
            }
        }
        return max_val;
    }
};