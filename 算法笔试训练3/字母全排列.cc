class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param str string�ַ���
     * @return string�ַ���vector
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
        //��ÿһ����ĸ����һ��ͷ����ʣ�����ĸȫ����
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