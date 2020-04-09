/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (57.55%)
 * Likes:    186
 * Dislikes: 0
 * Total Accepted:    36.3K
 * Total Submissions: 61.5K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
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
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)   return ans;
        DFS(root,sum);
        return ans;
    }
    void DFS(TreeNode* root, int target){
        path.push_back(root->val);
        if(target-root->val == 0 && !root->left && !root->right){
            ans.push_back(path);
        }
        if(root->left)  DFS(root->left, target - root->val);
        if(root->right) DFS(root->right,target - root->val);
        path.pop_back();
        
    }
};
// @lc code=end

/*
Accepted
114/114 cases passed (8 ms)
Your runtime beats 94.68 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (17 MB)*/