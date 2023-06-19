/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <algorithm>
#include <iterator>
#include <vector>
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pRoot TreeNode��
     * @return int����vector<vector<>>
     */

    vector<vector<int> > Print(TreeNode* pRoot) {
        if (pRoot == nullptr)
        {
            return  vector<vector<int>>();
        }
        queue<TreeNode*> q;
        q.push(pRoot);
        vector<vector<int>> vv;
        while (!q.empty())
        {
            vector<int> v;
            int size = q.size();
            while (size--)
            {
                TreeNode* tmp = q.front();
                v.push_back(tmp->val);
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            vv.push_back(v);
        }
        for (int i = 1; i < vv.size(); i += 2)
        {
            reverse(vv[i].begin(), vv[i].end());
        }
        return vv;
    }
};