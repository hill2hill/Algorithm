/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 *
 * https://leetcode-cn.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (42.95%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    32.9K
 * Total Submissions: 72.6K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 峰值元素是指其值大于左右相邻值的元素。
 * 
 * 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
 * 
 * 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
 * 
 * 你可以假设 nums[-1] = nums[n] = -∞。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1]
 * 输出: 2
 * 解释: 3 是峰值元素，你的函数应该返回其索引 2。
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,2,1,3,5,6,4]
 * 输出: 1 或 5 
 * 解释: 你的函数可以返回索引 1，其峰值元素为 2；
 * 或者返回索引 5， 其峰值元素为 6。
 * 
 * 
 * 说明:
 * 
 * 你的解法应该是 O(logN) 时间复杂度的。
 * 
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1) return 0;
        if(nums[0] > nums[1])   return 0;
        if(nums[sz-1] > nums[sz-2]) return sz-1;
        int left = 0, right = sz-1, mid;
        while(left < right){
            mid = (left + right) >> 1;
            if(mid == 0)    mid++;
            if(mid == sz -1)    mid--;
            if((nums[mid] > nums[mid-1]) && (nums[mid] > nums[mid+1]))  return mid;
            else if(nums[mid] < nums[mid+1])    left = mid + 1;
            else if(nums[mid] > nums[mid+1])    right = mid - 1;
        }
        return left;
    }
};
// @lc code=end

/*logN 推理出二分法
如果峰值在边界处，可以直接判断
如果峰值在中间区域，使用left+right+mid模式进行查找
    1.如果mid处比两旁的数字都大，那么说明找到了这个峰值
    2.如果mid小于mid+1处的值，说明至少存在一个峰值点在mid右侧
    3.如果mid大于mid+1处的值，说明至少存在一个峰值点在mid左侧
    （如果mid更新到两个边界处，将导致的无法进行两侧同时检查，是因为它只有一个邻居点，所以要进行一个修正操作）
59/59 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 34.74 % of cpp submissions (8.7 MB)*/