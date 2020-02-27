/*
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
    	if(!pRoot)	return true;
    	if(!pRoot->left && !pRoot->right)	return true;
    	if(pRoot->left->val != pRoot->right->val)	return false;
    	return check(pRoot->left, pRoot->right);
    }
    bool check(TreeNode* l, TreeNode* r){
    	if(!l && !r)	return true;
    	if(!(l && r))	return false;
    	if(l->val != r->val)	return false;
    	if(!l->left && !l->right && !r->right && !r->left)	return true;
    	bool flag = (l->left && r->right && l->right && r->left) || 
    		(l->left && r->right && !l->right && !r->left) ||
    		(!l->left && !r->right && l->right && r->left);

    	if(!flag)	return false;
    	return check(l->left, r->right) && check(l->right, r->left);	
    }

};