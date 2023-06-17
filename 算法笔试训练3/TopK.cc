class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param input int整型vector
     * @param k int整型
     * @return int整型vector
     */
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k)
    {
        if (k > input.size() || input.empty() || k <= 0)
        {
            return vector<int>();
        }
        //topK小，需要建大堆
        //[)左闭右开区间。
        priority_queue<int> pq(input.begin(), input.begin() + k);
        for (int i = k; i < input.size(); i++)
        {
            if (input[i] < pq.top())
            {
                pq.pop();
                pq.push(input[i]);
            }
        }
        vector<int> ret;
        //priority_queue没有迭代器
        while (!pq.empty())
        {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};