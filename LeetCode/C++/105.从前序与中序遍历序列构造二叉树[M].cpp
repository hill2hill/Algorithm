/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (62.45%)
 * Likes:    375
 * Dislikes: 0
 * Total Accepted:    51.5K
 * Total Submissions: 79.7K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)  return NULL;//空树直接返回
        return work(preorder,inorder,0,preorder.size()-1,0,preorder.size()-1);
    }
    TreeNode* work(vector<int> &preorder, vector<int> &inorder, int pleft, int pright, int ileft, int iright){
        
        TreeNode *root = new TreeNode(preorder[pleft]);
        if(pright == pleft)   return root;
        int ipos = ileft;
        for(; ipos < inorder.size(); ipos++){
            if(inorder[ipos] ==preorder[pleft]){
                break;
            }   
        }
        if(ipos>ileft)    root->left = work(preorder, inorder,pleft+1 , pleft+ipos-ileft, ileft, ipos-1);
        if(ipos<iright)   root->right = work(preorder, inorder,pleft+ipos-ileft+1, pright,ipos+1, iright);

        return root;
    }
    
};
// @lc code=end

/*
[1]\n [1]
Accepted
203/203 cases passed (48 ms)
Your runtime beats 24.93 % of cpp submissions
Your memory usage beats 38.51 % of cpp submissions (17.5 MB)
*/