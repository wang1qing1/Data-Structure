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
     * @param root TreeNode��
     * @param target int����
     * @return int����vector<vector<>>
     */
    void _findPath(TreeNode* root, vector<vector<int>>& ret, vector<int>& list, int target)
    {
        if (root == nullptr)
        {
            return;
        }
        //������·��
        list.push_back(root->val);
        //target����,ÿ�μ�ȥ·���ϵĽ�㣬ֻ��target==0ʱ��Ҳ������ζ�ţ��Ӹ��ڵ㵽��ǰ�Ľ��֮���ǵ���target
        //�����ǰ�����һ����Ҷ�ӽڵ㣬Ҳ��һ��������·��
        target -= root->val;
        if (nullptr == root->left && nullptr == root->right && target == 0)
        {
            ret.push_back(list);
        }
        //DFS   
        _findPath(root->left, ret, list, target);
        _findPath(root->right, ret, list, target);
        //����
        list.pop_back();

    }
    vector<vector<int> > FindPath(TreeNode* root, int target) {
        vector<vector<int>>  ret;//�����
        vector<int> list;//·��

        _findPath(root, ret, list, target);

        return ret;
    }
};