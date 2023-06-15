class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int NumberOf1(int n) {
        int num = n;
        int count = 0;
        while (num)
        {
            num &= (num - 1);//避免无效检测。
            count++;
        }
        return count;
    }
};