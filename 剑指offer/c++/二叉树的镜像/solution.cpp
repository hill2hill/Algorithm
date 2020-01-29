/*
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
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
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == nullptr)    return;

        Mirror(pRoot -> left);
        Mirror(pRoot -> right);

        TreeNode* p = pRoot -> left;
        pRoot -> left = pRoot -> right;
        pRoot -> right = p;
    }
};

/*
使用后序遍历的公式，直接解决
先将左右子树化为镜像，然后根节点更换左膀右臂
*/