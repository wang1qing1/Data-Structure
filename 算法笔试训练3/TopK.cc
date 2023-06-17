class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param input int����vector
     * @param k int����
     * @return int����vector
     */
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k)
    {
        if (k > input.size() || input.empty() || k <= 0)
        {
            return vector<int>();
        }
        //topKС����Ҫ�����
        //[)����ҿ����䡣
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
        //priority_queueû�е�����
        while (!pq.empty())
        {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};