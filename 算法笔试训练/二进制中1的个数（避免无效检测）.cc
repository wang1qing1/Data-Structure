class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param n int����
     * @return int����
     */
    int NumberOf1(int n) {
        int num = n;
        int count = 0;
        while (num)
        {
            num &= (num - 1);//������Ч��⡣
            count++;
        }
        return count;
    }
};