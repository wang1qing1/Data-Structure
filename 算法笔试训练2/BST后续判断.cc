class Solution {
public:
    bool _VerifySquenceOfBST(vector<int> sequence, int begin, int end)
    {
        if (begin > end)
        {
            return true;
        }
        int mid = sequence[end];
        int i = 0;
        while (sequence[i] < mid)
        {
            i++;
        }
        int j = i;
        while (j < end)
        {
            if (sequence[j] < mid)
            {
                return false;
            }
            j++;
        }
        return _VerifySquenceOfBST(sequence, 0, i - 1) && _VerifySquenceOfBST(sequence, i, end - 1);
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
        {
            return false;
        }

        return _VerifySquenceOfBST(sequence, 0, sequence.size() - 1);

    }
};