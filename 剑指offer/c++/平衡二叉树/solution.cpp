/*题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。*/
//递归，并注意附加条件
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot)    return true;
        int left, right;
        left = TreeDepth(pRoot -> left);
        right = TreeDepth(pRoot -> right);
        
        return abs(left - right) < 2 
            && IsBalanced_Solution(pRoot -> left) 
            && IsBalanced_Solution(pRoot -> right);
    }
    int TreeDepth(TreeNode* pRoot){
        if(!pRoot)    return 0;
        int left, right;
        left = TreeDepth(pRoot -> left);
        right = TreeDepth(pRoot -> right);
        return ((left > right)? left : right)+1;
    }
};