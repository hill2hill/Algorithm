/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (35.72%)
 * Likes:    418
 * Dislikes: 0
 * Total Accepted:    40.8K
 * Total Submissions: 108.6K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)   return 0;
        
        //两个vector,一个记录最大乘积 另一个记录最小
        vector<int> high(size, nums[0]), low(size, nums[0]);
        int max_ans = high[0];
        for(int i = 1; i < size; i++){
            if(nums[i] >= 0){
                high[i] = max(nums[i]*high[i-1], nums[i]);
                low[i] = min(nums[i]*low[i-1], nums[i]);
            }
            else{
                high[i] = max(nums[i]*low[i-1], nums[i]);
                low[i] = min(nums[i]*high[i-1], nums[i]);
            }

            if(high[i] > max_ans) max_ans = high[i];
        }
        return max_ans;
    }
};
// @lc code=end

/*同时记录最大值、最小值的动态规划
184/184 cases passed (8 ms)
Your runtime beats 65.63 % of cpp submissions
Your memory usage beats 6.25 % of cpp submissions (11.8 MB)
*/