class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        if (data.empty())
        {
            return;
        }
        int sum = 0;
        //������ȫ��^���㵽һ�����յõ�����ֻ����һ�ε�����(x,y)�����(x^y)
        for (int i = 0; i < data.size(); i++)
        {
            sum ^= data[i];
        }
        if (sum == 0)
        {
            return;
        }
        int pos = 1;
        //�ҵ�����������У�����λΪ1��һλ������sum=x^y;�����pos����λ�����ǡ�1��
        //Ҳ����ζ�ţ�x��y��pos����λ�ϲ���ͬ����Ϊ0^1=1 or 1^0=1;
        //����һ�����У�����һ������pos����λ��Ҫô�ǡ�1��Ҫô�ǡ�0��;
        //�����Ϳ��԰�����ֳ������֣�pos����λΪ��1����pos����λΪ��0��,��ͬ������pos����λ�ض���ͬ���ض��ֵ�ͬһ�顣
        //�ؼ��ǣ�x��y,���ڡ�x��y��pos����λ�ϲ���ͬ��Ҳ�ᱻ�ֿ��������У�Ȼ���ٴ�ͨ������ҵ����ǡ�
        while (!(sum & (pos)))
        {
            pos <<= 1;
        }
        *num1 = 0;
        *num2 = 0;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] & pos)
            {
                *num1 ^= data[i];
            }
            else
            {
                *num2 ^= data[i];
            }
        }
    }

};