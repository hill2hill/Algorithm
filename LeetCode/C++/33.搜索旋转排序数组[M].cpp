/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (36.16%)
 * Likes:    532
 * Dislikes: 0
 * Total Accepted:    77.9K
 * Total Submissions: 213.8K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0)    return -1;
        int left = 0, right = len-1;
        int high, low;
        if(nums[left] <= nums[right]){
            high = len -1;
            low = 0;
        }
        else{
            while(1){
                int mid = (left+right)/2;
                if(nums[mid] > nums[mid+1]){
                    high = mid, low = mid+1;
                    break;
                }
                else if(nums[mid] >= nums[left]){
                    left = mid+1;
                }
                else if(nums[mid] <= nums[right]){
                    right = mid-1;
                }
            }
        }

        if(target > nums[high] || target < nums[low])   return -1;
        if(target >= nums[0]){
            left = 0, right = high;  
        }
        else if(target <= nums[len-1]){
            left = low, right = len-1;
        }
        while(left <=right){
            int mid = (left+right)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid+1;
            else if(nums[mid] > target) right = mid-1;
        }
        return -1;
    }
};
// @lc code=end

/* 二分法 先分开两个区间，再在对应区间内搜索
196/196 cases passed (8 ms)
Your runtime beats 45.7 % of cpp submissions
Your memory usage beats 5.04 % of cpp submissions (13.5 MB)
*/

/*
196/196 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 5.04 % of cpp submissions (13.5 MB)*/