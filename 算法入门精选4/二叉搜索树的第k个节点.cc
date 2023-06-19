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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param proot TreeNode类
     * @param k int整型
     * @return int整型
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
        //k大于节点数，也返回-1 
        if (k > countnode)
        {
            return -1;
        }
        return num;
    }
};