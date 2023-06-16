/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
//ע�⣺�������������ö�����A��B���ж�B�ǲ���A���ӽṹ�����������ṹ
class Solution {
public:

    bool isSametree(TreeNode* root1, TreeNode* root2)
    {
        if (root2 == nullptr)//˵��root2�Ѿ�������
        {
            return true;
        }
        if (root1 == nullptr)//root���н�㣬root1
        {
            return false;
        }
        if (root1->val != root2->val)//������㶼����NULL�������ýڵ��Ƿ���ͬ��
        {
            return false;
        }
        if (isSametree(root1->left, root2->left) && isSametree(root1->right, root2->right))
            return true;
        else
            return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr)
        {
            return false;
        }
        bool result = false;
        if (pRoot1->val == pRoot2->val)
        {
            result = isSametree(pRoot1, pRoot2);
        }
        if (result)
        {
            return true;
        }
        if (HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2))
            return true;
        else
            return false;
    }
};
