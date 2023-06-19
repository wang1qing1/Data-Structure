/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param proot TreeNode��
     * @param k int����
     * @return int����
     */
    void midK(TreeNode* proot, int& k, int& num, int& count)
    {
        if (proot == nullptr)
        {
            return;
        }
        midK(proot->left, k, num, count);
        if (k == 1)
        {
            num = proot->val;
        }
        count++;
        k--;
        midK(proot->right, k, num, count);
    }
    int KthNode(TreeNode* proot, int k) {
        if (proot == nullptr || k <= 0)
        {
            return -1;
        }
        int num;
        int tmpk = k;
        int countnode = 0;
        midK(proot, tmpk, num, countnode);
        //k���ڽڵ�����Ҳ����-1 
        if (k > countnode)
        {
            return -1;
        }
        return num;
    }
};