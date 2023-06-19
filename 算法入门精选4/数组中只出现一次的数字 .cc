class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        if (data.empty())
        {
            return;
        }
        int sum = 0;
        //将数据全部^运算到一起，最终得到两个只出现一次的数字(x,y)的异或(x^y)
        for (int i = 0; i < data.size(); i++)
        {
            sum ^= data[i];
        }
        if (sum == 0)
        {
            return;
        }
        int pos = 1;
        //找到他们异或结果中，比特位为1的一位，由于sum=x^y;所如果pos比特位置上是‘1’
        //也就意味着，x和y在pos比特位上不相同，因为0^1=1 or 1^0=1;
        //在这一组数中，任意一个数，pos比特位上要么是‘1’要么是‘0’;
        //这样就可以把数组分成两部分，pos比特位为‘1’，pos比特位为‘0’,相同的数，pos比特位必定相同，必定分到同一组。
        //关键是，x和y,由于‘x和y在pos比特位上不相同‘也会被分开到两组中，然后再次通过异或，找到他们。
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