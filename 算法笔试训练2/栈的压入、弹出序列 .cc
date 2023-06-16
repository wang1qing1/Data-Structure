class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pushV int����vector
     * @param popV int����vector
     * @return bool������
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
            st.push(pushV[i]);//ѭ����ջ��
            while (!st.empty() && st.top() == popV[j])//ÿ�ν�ջ������Ա��Ƿ���Գ�ջ��
            {
                st.pop();
                j++;
            }
        }
        //����ջ���ݣ��Ѿ�ȫ������ջ��
        //1.���ջ�л������ݣ��Ǿ���st.top()!=popV[j]��˳����ȷ
        //2.���ջ��û�����ݣ��Ǿ���st.empty(),˳����ȷ
        return st.empty();
    }
};