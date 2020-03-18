/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (38.05%)
 * Likes:    328
 * Dislikes: 0
 * Total Accepted:    66K
 * Total Submissions: 168.8K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int len = nums.size();
        if(len == 0)    return ans;
        if(nums[0] > target || nums[len-1] < target)
            return ans;
        
        int left = 0, right = len-1;
        if(nums[0] == target)    ans[0] = 0;
        else{
           while(left <= right){
               int mid = (left+right)/2;
               if(nums[mid] == target && nums[mid-1] != target){
                   ans[0] = mid;
                   break;
               }
               else if(nums[mid] >= target) right = mid - 1;
               else left = mid + 1;
           }
        }
        if(ans[0] == -1)    return ans;

        left = 0, right = len-1;
        if(nums[len-1] == target){
            ans[1] = len-1;
        }
        else{
            while(left <= right){
                int mid = (left+right)/2;
                if(nums[mid] == target && nums[mid+1] != target){
                    ans[1] = mid;
                    break;
                }
                else if(nums[mid] <= target)    left = mid+1;
                else    right = mid-1;
            }
        }

        return ans;
    }
};
// @lc code=end

/*
两次二分查找
88/88 cases passed (4 ms)
Your runtime beats 98.76 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (9.5 MB)
*/