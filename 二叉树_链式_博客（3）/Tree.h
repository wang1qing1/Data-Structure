#pragma once






BTNode* BTNodeCreat(int val);

void PrevOrder(BTNode* root);

int SizeNode(BTNode* root);

int LeafSize(BTNode* root);

BTNode* FindNode(BTNode* root, int x);

int BTKSize(BTNode* root, int k);

int BTdeep(BTNode* root);

bool isSameTree(struct TreeNode* p, struct TreeNode* q);

bool isUnivalTree(struct TreeNode* root);

void LevelOrder(BTNode* root);

bool TreeComplete(BTNode* root);

void TreeDestory(BTNode* root);