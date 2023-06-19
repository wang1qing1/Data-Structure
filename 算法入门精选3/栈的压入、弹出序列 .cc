class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pushV int整型vector
     * @param popV int整型vector
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        if (pushV.size() != popV.size() || pushV.empty() || popV.empty())
        {
            return false;
        }
        stack<int> st;
        int j = 0;
        for (int i = 0; i < pushV.size(); i++)
        {
            st.push(pushV[i]);//循环进栈，
            while (!st.empty() && st.top() == popV[j])//每次进栈都检查以便是否可以出栈。
            {
                st.pop();
                j++;
            }
        }
        //当进栈数据，已经全部进入栈中
        //1.如果栈中还有数据，那就是st.top()!=popV[j]，顺序不正确
        //2.如果栈中没有数据，那就是st.empty(),顺序正确
        return st.empty();
    }
};