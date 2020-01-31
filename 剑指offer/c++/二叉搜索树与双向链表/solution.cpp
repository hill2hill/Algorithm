/*

题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(! pRootOfTree)	return NULL;
        TreeNode *LeftTreeResult, *RightTreeResult;
        LeftTreeResult = Convert(pRootOfTree -> left);
        RightTreeResult = Convert(pRootOfTree -> right);

        TreeNode *LeftTreeRightSide = ToRight(LeftTreeResult);
        if(LeftTreeResult){
        	LeftTreeRightSide -> right = pRootOfTree;
        	pRootOfTree -> left = LeftTreeRightSide;
        }
        else{
        	pRootOfTree -> left = LeftTreeRightSide;
        }

        if(RightTreeResult){
        	pRootOfTree -> right = RightTreeResult;
        	RightTreeResult -> left = pRootOfTree;
        }

        while(pRootOfTree -> left){
        	pRootOfTree = pRootOfTree -> left;
        }

        return pRootOfTree;
    }

    TreeNode* ToRight(TreeNode* LeftSide){
    	if(!LeftSide)	return NULL;
    	while(LeftSide -> right){
    		LeftSide = LeftSide -> right;
    	}
    	return LeftSide;
    }
};