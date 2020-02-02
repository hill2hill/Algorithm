/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (47.94%)
 * Likes:    1548
 * Dislikes: 0
 * Total Accepted:    149.7K
 * Total Submissions: 306.7K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
          int len = nums.size();
          if(len == 1)  return nums[0];
          int max = nums[0], current = nums[0];
          for(int i = 1; i < len; i++){
              if(current < 0){
                  if(nums[i] > current){
                      current = nums[i];
                      if(current > max){//每次想改max的值都要看看是否合格才可以进行值替换
                          max = current;
                      }
                      
                  }
              }
              else if(current >= 0){//大于等于零都可以有机会成为一分子，不能只大于零的人搞特殊
                  if(nums[i] >= 0){
                      current += nums[i];
                      if(current > max){
                          max = current;
                      }
                  }
                  else if(nums[i] < 0){
                      if(current + nums[i] >= 0){
                          current += nums[i];
                      }
                      else{
                          current = nums[i];
                      }
                  }
              }
          }
          return max;
    }
};
// @lc code=end

/*
202/202 cases passed (8 ms)
Your runtime beats 81.94 % of cpp submissions
Your memory usage beats 18.02 % of cpp submissions (9.4 MB)
*/