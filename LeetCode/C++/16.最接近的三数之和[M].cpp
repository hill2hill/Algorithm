/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (41.97%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    53.5K
 * Total Submissions: 127.5K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size(), in_delta = INT_MAX, out_delta = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<len-2; i++){
            int twoSumClosest = target - nums[i];
            int left = i+1, right = len-1;
            in_delta = INT_MAX;
            while(left<right){    
                if(abs(twoSumClosest-nums[left]-nums[right])<=abs(in_delta)){
                    in_delta = twoSumClosest-nums[left]-nums[right];
                }
                if(twoSumClosest-nums[left]-nums[right] > 0)    left++;
                else    right--;
            }
            if(in_delta == 0)   return target;
            if(abs(in_delta) < abs(out_delta))  out_delta = in_delta;
            //else break;
        }

        return target - out_delta;
    }
};
// @lc code=end

//"[0,2,1,-3]\n1"
//"[-55,-24,-18,-11,-7,-3,4,5,6,9,11,23,33]\n0"

/*
125/125 cases passed (8 ms)
Your runtime beats 90.47 % of cpp submissions
Your memory usage beats 5.46 % of cpp submissions (9 MB)
*/