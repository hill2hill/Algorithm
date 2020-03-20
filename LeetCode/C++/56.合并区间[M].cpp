/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (39.02%)
 * Likes:    317
 * Dislikes: 0
 * Total Accepted:    61.8K
 * Total Submissions: 152.1K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len <= 1)    return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> tmp = intervals[0];

        for(int i = 1; i<len;i++){
            if(intervals[i][0] <= tmp[1]){
                tmp[1] = intervals[i][1] > tmp[1] ? intervals[i][1] : tmp[1];
            }
            else{
                ans.push_back(tmp);
                tmp = intervals[i];
            }
        }
        ans.push_back(tmp);
        return ans;
    }
    
};
// @lc code=end

/*
先将所有区间按照左端点由小到大的顺序排列
如果新的区间左端点在现有区间内，进行合并
如果不在，开辟一个新的区间，将已有区间进行存储
ps：最后别遗漏最后一个空间

169/169 cases passed (20 ms)
Your runtime beats 82.08 % of cpp submissions
Your memory usage beats 73.6 % of cpp submissions (12.3 MB)
*/