class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return string字符串vector
    */
    void swap(string& str, int i, int j)
    {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
    void _Permutation(string& str, unordered_set<string>& s, int start)
    {
        if (start == str.length())
        {
            s.insert(str);
            return;
        }
        //让每一个字母都当一次头，对剩余的字母全排列
        for (int i = start; i < str.length(); i++)
        {
            swap(str, start, i);
            _Permutation(str, s, start + 1);
            swap(str, start, i);
        }

    }

    vector<string> Permutation(string str) {
        vector<string> result;
        unordered_set<string> s;
        int start = 0;
        _Permutation(str, s, start);
        for (auto it = s.begin(); it != s.end(); it++)
        {
            result.push_back(*it);
        }
        return result;
    }
};