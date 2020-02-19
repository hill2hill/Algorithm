/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (35.97%)
 * Likes:    310
 * Dislikes: 0
 * Total Accepted:    39.2K
 * Total Submissions: 109K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int N = nums.size();
        vector<vector<int> > ans;
        if(N < 4)   return ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<N-3;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<N-2; j++){
                if(j>i+1&&nums[j]==nums[j-1])   continue;
                int l=j+1, r=N-1;
                while(l<r){
                    int sum = nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum > target)    r--;
                    else if(sum < target)   l++;
                    else{
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l<r&&nums[l]==nums[++l]);
                        while(l<r&&nums[r]==nums[--r]);
                    }
                }
            }
        }


        return ans;
    }
};
// @lc code=end

/*
282/282 cases passed (48 ms)
Your runtime beats 62.43 % of cpp submissions
Your memory usage beats 9.02 % of cpp submissions (9.6 MB)
*/

/*O(N^3)Memory Limit Exceeded 内存爆了？不是应该时间太久么？
        vector<vector<int>> ans;
        int size = nums.size();
        if (size < 4)
            return ans;
        int a, b, c, d;
        sort(nums.begin(), nums.end());
        for (a = 0; a < size - 3; a++)
        {
            for (b = a + 1; b < size - 2; b++)
            {
                c = b + 1, d = size - 1;
                while (c < d)
                {
                    if (nums[a] + nums[b] + nums[c] + nums[d] == target)
                    {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while (nums[c] == nums[c + 1])
                            c++;
                        while (nums[d] == nums[d - 1])
                            d--;
                    }
                    else if (nums[a] + nums[b] + nums[c] + nums[d] > target)
                    {
                        d--;//死循环了！！！！
                    }
                    else if (nums[a] + nums[b] + nums[c] + nums[d] < target)
                    {
                        c++;//死循环了！！！！
                    }
                }
                while (nums[b] == nums[b + 1])
                    b++;
            }
            while (nums[a] == nums[a + 1])
                a++;
        }

        return ans;
*/