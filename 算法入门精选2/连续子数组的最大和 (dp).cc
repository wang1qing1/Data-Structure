class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型
     */
    int FindGreatestSumOfSubArray(vector<int>& array) {

        int* dp = new int[array.size()];
        //1.定义状态
        //f(i)以i下标结尾的最大连续子序列的和.
        //2.状态转移方程
        //f(i)=max(f(i-1)+array[i],array[i]);
        //f(i)只会有两个来源，第一个是f(i-1)+array[i],第二个是就是array[i].
        //3.初始状态
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