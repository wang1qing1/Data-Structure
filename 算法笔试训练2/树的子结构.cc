/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
//注意：这里是输入两棵二叉树A，B，判断B是不是A的子结构。并非子树结构
class Solution {
public:

    bool isSametree(TreeNode* root1, TreeNode* root2)
    {
        if (root2 == nullptr)//说明root2已经找完了
        {
            return true;
        }
        if (root1 == nullptr)//root还有结点，root1
        {
            return false;
        }
        if (root1->val != root2->val)//两个结点都不是NULL，看看该节点是否相同。
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
