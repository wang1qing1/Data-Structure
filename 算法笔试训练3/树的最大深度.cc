
struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) 
        :val(x), left(NULL), right(NULL) 
    {}
};
class Solution1 {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (pRoot == nullptr)
        {
            return 0;
        }
        //树的最大深度等于，左右子树中最大的深度+1
        int LDepth = TreeDepth((pRoot->left));
        int RDepth = TreeDepth((pRoot->right));
        return 1 + (LDepth > RDepth ? LDepth : RDepth);
    }
};


class Solution {
public:
    //递归查找每一条路径，记录当前路径长度，当走到根节点时，更新max记录最长的路径
    void _TreeDepth(TreeNode* pRoot, int& max, int depth)
    {
        if (pRoot == nullptr)
        {
            if (max < depth)
            {
                max = depth;
            }
            return;
        }
        _TreeDepth(pRoot->left, max, depth + 1);
        _TreeDepth(pRoot->right, max, depth + 1);

    }
    int TreeDepth(TreeNode* pRoot) {
        if (pRoot == nullptr)
        {
            return 0;
        }
        int max = 0;
        _TreeDepth(pRoot, max, 0);
        return max;
    }
};