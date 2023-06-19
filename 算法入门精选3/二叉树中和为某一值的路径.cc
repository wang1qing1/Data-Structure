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
     * @param root TreeNode类
     * @param target int整型
     * @return int整型vector<vector<>>
     */
    void _findPath(TreeNode* root, vector<vector<int>>& ret, vector<int>& list, int target)
    {
        if (root == nullptr)
        {
            return;
        }
        //结点进入路径
        list.push_back(root->val);
        //target计算,每次减去路径上的结点，只有target==0时，也就是意味着，从根节点到当前的结点之和是等于target
        //如果当前结点是一个，叶子节点，也就一个完整的路径
        target -= root->val;
        if (nullptr == root->left && nullptr == root->right && target == 0)
        {
            ret.push_back(list);
        }
        //DFS   
        _findPath(root->left, ret, list, target);
        _findPath(root->right, ret, list, target);
        //回退
        list.pop_back();

    }
    vector<vector<int> > FindPath(TreeNode* root, int target) {
        vector<vector<int>>  ret;//结果集
        vector<int> list;//路径

        _findPath(root, ret, list, target);

        return ret;
    }
};