class Solution {
public:
    int rectCover(int number) {
        int f1 = 1;
        int f2 = 2;
        if (number <= 2)
        {
            return number;
        }
        //f(n)-------2*n的矩形的覆盖方式数
        //f(n)=f(n-1)+f(n-2);最后一块是竖着放+最后一块是横着放。
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