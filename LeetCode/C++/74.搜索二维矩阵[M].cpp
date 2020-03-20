/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (36.33%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    35.6K
 * Total Submissions: 94.6K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 * 
 * 
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * 输出: false
 * 
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0)   return false;
        int cols = matrix[0].size();
        if(cols == 0)   return false;
        if(target < matrix[0][0] || target > matrix[rows-1][cols-1])    return false;

        int up = 0, down = rows-1, mid;
        if(target >= matrix[down][0])   mid = down;
        else while(up <= down){
            mid = (up+down)/2;
            if(matrix[mid][0] <= target && matrix[mid+1][0] > target)
                break;
            else if(matrix[mid][0] < target)    up = mid+1;
            else down = mid -1;
        }
        
        

        int left = 0, right = cols-1, mid2;
        while(left <= right){
            mid2 = (left+right)/2;
            if(matrix[mid][mid2] == target) return true;
            else if(matrix[mid][mid2] < target) left = mid2+1;
            else right = mid2-1;
        }

        return false;
    }
};
// @lc code=end

/*
136/136 cases passed (12 ms) 两次二分，我糊涂了----》可以变成一次二分
Your runtime beats 55.17 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.9 MB)

[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n23 特殊处理最后一行

[[1,3,5]]\n1
*/
