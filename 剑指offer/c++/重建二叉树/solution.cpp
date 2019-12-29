/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8} 和 中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。*/
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        //if(pre.size() != vin.size()) return NULL;
        if(pre.size() == 0) return NULL;
        TreeNode* p = new TreeNode(pre[0]);
        //p -> val = pre[0];
        if(pre.size() == 1) return p;
        int p_vin = 0;
        vector<int> pre_left, pre_right, vin_left, vin_right;
        while(vin[p_vin] != pre[0]){
            pre_left.push_back(pre[p_vin+1]);
            vin_left.push_back(vin[p_vin]);
            p_vin++;
        }
        p_vin ++;
        while(p_vin < pre.size()){
            pre_right.push_back(pre[p_vin]);
            vin_right.push_back(vin[p_vin]);
            p_vin++;
        }
        p -> left = reConstructBinaryTree(pre_left, vin_left);
        p -> right = reConstructBinaryTree(pre_right, vin_right);

        return p;
    }
};