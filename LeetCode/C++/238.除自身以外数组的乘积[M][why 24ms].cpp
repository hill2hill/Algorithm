/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 *
 * https://leetcode-cn.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (63.93%)
 * Likes:    335
 * Dislikes: 0
 * Total Accepted:    31.9K
 * Total Submissions: 47.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i]
 * 之外其余各元素的乘积。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [1,2,3,4]
 * 输出: [24,12,8,6]
 * 
 * 
 * 
 * 提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
 * 
 * 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
 * 
 * 进阶：
 * 你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        if(!sz) return vector<int> ();
        vector<int> ans(sz,1);

        int tmp = nums[0];
        for(int i = 1; i < sz; i++){
            ans[i] *= tmp;
            tmp *= nums[i];
        }

        tmp = nums[sz-1];
        for(int i = sz-2; i > 0; i--){
            ans[i] *= tmp;
            tmp *= nums[i];
        }
        ans[0] *= tmp;

        return ans;
    }
};
// @lc code=end

/* 怎么这么慢

18/18 cases passed (24 ms)
Your runtime beats 37.5 % of cpp submissions
Your memory usage beats 14.29 % of cpp submissions (15.3 MB)
*/