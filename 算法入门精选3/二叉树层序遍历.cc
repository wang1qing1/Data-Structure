/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {

        vector<int> ret;
        if (root == nullptr)
        {
            return ret;
        }
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty())
        {
            TreeNode* tmp = qu.front();
            qu.pop();
            ret.push_back(tmp->val);
            if (tmp->left) {
                qu.push(tmp->left);
            }
            if (tmp->right)
            {
                qu.push(tmp->right);
            }
        }
        return ret;
    }
};
