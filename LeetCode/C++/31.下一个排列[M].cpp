/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (32.19%)
 * Likes:    396
 * Dislikes: 0
 * Total Accepted:    44.4K
 * Total Submissions: 135.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1)    return;
        for(int i = len - 2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                int x = findx(nums, i);
                swap(nums[i],nums[x]);
                sort(nums.begin()+i+1, nums.end());
                //在i位置后寻找大于nums[i]的nums[*],二者交换然后对i后序列排序
                return;
            }
        }
        sort(nums.begin(),nums.end());
    }
    int findx(vector<int>& nums, int i){
        int x = i+1, len = nums.size();
        for(int j = i+1; j < len; j++){
            if(nums[j] > nums[i] && nums[j] < nums[x]){
                x = j;
            }
        }
        return x;
    }
};
// @lc code=end

/*
1.如果纯降序，那把vector排成纯升序
2.如果不是：寻找下一排序
265/265 cases passed (4 ms)
Your runtime beats 90.25 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.3 MB)
*/
