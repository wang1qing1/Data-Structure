#define _CRT_SECURE_NO_WARNINGS 1
#include"AVL.hpp"

int main()
{
	AVLTree<int,int> root;
	root.insert(pair<int,int>(10, 0));
	/*root.Midorder();
	cout << endl;*/
	root.insert(pair<int, int>(11, 0));
	/*root.Midorder();
	cout << endl;*/
	root.insert(pair<int, int>(12, 0));
	/*root.Midorder();
	cout << endl;*/
	root.insert(pair<int, int>(3, 0));
	/*root.Midorder();
	cout << endl;*/
	root.insert(pair<int, int>(4, 0));
	/*root.Midorder();
	cout << endl;*/
	root.insert(pair<int, int>(0, 0));
	root.insert(pair<int, int>(10, 0));
	root.insert(pair<int, int>(15, 0));

	root.Midorder();

	//cout << root.isAVLTree();
	return 0;
}