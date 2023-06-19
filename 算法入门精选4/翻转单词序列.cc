class Solution {
public:
    void Reserve(string& str, int left, int right)
    {
        while (left < right)
        {
            swap(str[left], str[right]);
            left++;
            right--;
        }
    }
    string ReverseSentence(string str) {

        int left = 0;
        int right = 0;
        while (right < str.length())
        {
            if (str[right] != ' ')
            {
                right++;
            }
            else
            {
                Reserve(str, left, right - 1);
                left = right + 1;
                right++;
            }
        }
        Reserve(str, left, right - 1);
        Reserve(str, 0, str.length() - 1);
        return str;
    }
};