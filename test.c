#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef struct TreeNode {
    char val;
    struct TreeNode* left;
    struct TreeNode* right;

}TNode;
//Leetcode----144. 二叉树的前序遍历

int NodeSize(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return NodeSize(root->left) + NodeSize(root->right) + 1;
}
void _preTrave(struct TreeNode* root, int* arr, int* pi)
{
    if (root == NULL)
    {
        return;
    }
    arr[*pi] = root->val;
    (*pi)++;
    _preTrave(root->left, arr, pi);
    _preTrave(root->right, arr, pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int i = 0;
    int size = NodeSize(root);
    int* arr = (int*)malloc(sizeof(int) * size);
    _preTrave(root, arr, &i);
    *returnSize = size;
    return arr;
}

//Leetcode ----104. 二叉树的最大深度
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
    {
        return 0;
    }
    //return maxDepth(root->left)>maxDepth(root->right)?maxDepth(root->left)+1:maxDepth(root->right)+1;

    int depthleft = maxDepth(root->left);
    int depthright = maxDepth(root->right);
    return depthleft > depthright ? depthleft + 1 : depthright + 1;
}


//Leetcode----110. 平衡二叉树
int maxDepth(struct TreeNode* root){
    if(root==NULL)
    {
        return 0;
    }
    int depthleft=maxDepth(root->left);
    int depthright=maxDepth(root->right);
    return depthleft>depthright?depthleft+1:depthright+1;
}
bool isBalanced(struct TreeNode* root){
    if(root==NULL)
    {
        return true;
    }
    int depthleft=maxDepth(root->left);
    int depthright=maxDepth(root->right);
    if(abs(depthleft-depthright)<2&&isBalanced(root->left)&&isBalanced(root->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//二叉树的创建
TNode* CreatTree()
{
    char a = 0;
    scanf("%c", &a);
    if (a == ' ')
    {
        return NULL;
    }
    TNode* root = (TNode*)malloc(sizeof(TNode));
    root->val = a;
    root->left= CreatTree(root->left);
    root->right= CreatTree(root->right);
    return root;
}

void ProOrder(TNode* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c", root->val);
    ProOrder(root->left);
    ProOrder(root->right);
}

int main()
{
    TNode*Tree=CreatTree();
    ProOrder(Tree);

}

