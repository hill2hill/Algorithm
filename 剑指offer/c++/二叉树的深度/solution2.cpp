/*
题目描述

输入一棵二叉树，求该树的深度。

从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

//思路：递归
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
    	if(!pRoot)	return 0;
    	int left, right;
    	left = TreeDepth(p->left);
    	right = TreeNode(p->right);
    	return ((left > right)? left : right)  +1;
    }
};