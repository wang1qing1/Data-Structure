class Solution {
public:
    int rectCover(int number) {
        int f1 = 1;
        int f2 = 2;
        if (number <= 2)
        {
            return number;
        }
        //f(n)-------2*n�ľ��εĸ��Ƿ�ʽ��
        //f(n)=f(n-1)+f(n-2);���һ�������ŷ�+���һ���Ǻ��ŷš�
        int fn;
        for (int i = 3; i <= number; i++)
        {
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
};