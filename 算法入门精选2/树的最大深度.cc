
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
        //���������ȵ��ڣ������������������+1
        int LDepth = TreeDepth((pRoot->left));
        int RDepth = TreeDepth((pRoot->right));
        return 1 + (LDepth > RDepth ? LDepth : RDepth);
    }
};


class Solution {
public:
    //�ݹ����ÿһ��·������¼��ǰ·�����ȣ����ߵ����ڵ�ʱ������max��¼���·��
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