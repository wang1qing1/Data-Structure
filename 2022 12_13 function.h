#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;
struct Node
{
	struct Node* Child1; // 第一个孩子
	struct Node* Child2; // 第二个孩子
	//
	// ...... 不能确定孩子书数
	//
	DataType data; // 结点中的数据域

};
typedef int BTDataType;
// 二叉链
struct BinaryTreeNode
{
	struct BinTreeNode* _pLeft; // 指向当前节点左孩子
	struct BinTreeNode* _pRight; // 指向当前节点右孩子
	BTDataType _data; // 当前节点值域
};
// 三叉链
struct BinaryTreeNode
{
	struct BinTreeNode* _pParent; // 指向当前节点的双亲
	struct BinTreeNode* _pLeft; // 指向当前节点左孩子
	struct BinTreeNode* _pRight; // 指向当前节点右孩子
	BTDataType _data; // 当前节点值域
};
