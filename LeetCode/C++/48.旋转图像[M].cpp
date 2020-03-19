/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 *
 * https://leetcode-cn.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (65.30%)
 * Likes:    389
 * Dislikes: 0
 * Total Accepted:    60.8K
 * Total Submissions: 90.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵表示一个图像。
 * 
 * 将图像顺时针旋转 90 度。
 * 
 * 说明：
 * 
 * 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
 * 
 * 示例 1:
 * 
 * 给定 matrix = 
 * [
 * ⁠ [1,2,3],
 * ⁠ [4,5,6],
 * ⁠ [7,8,9]
 * ],
 * 
 * 原地旋转输入矩阵，使其变为:
 * [
 * ⁠ [7,4,1],
 * ⁠ [8,5,2],
 * ⁠ [9,6,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 给定 matrix =
 * [
 * ⁠ [ 5, 1, 9,11],
 * ⁠ [ 2, 4, 8,10],
 * ⁠ [13, 3, 6, 7],
 * ⁠ [15,14,12,16]
 * ], 
 * 
 * 原地旋转输入矩阵，使其变为:
 * [
 * ⁠ [15,13, 2, 5],
 * ⁠ [14, 3, 4, 1],
 * ⁠ [12, 6, 8, 9],
 * ⁠ [16, 7,10,11]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n <= 1)  return;
        for(int depth = 0; depth < n/2; depth++){
            for(int i = 0; i < n- 2*depth -1; i++){
                int tmp = matrix[depth][depth+i]; //左上暂存

                matrix[depth][depth+i] = matrix[n-1-depth-i][depth];//左上 = 左下

                matrix[n-1-depth-i][depth] = matrix[n-1-depth][n-1-depth-i];//左下 = 右下
                
                matrix[n-1-depth][n-1-depth-i] = matrix[depth+i][n-1-depth];//右下 = 右上
                
                matrix[depth+i][n-1-depth] = tmp;
            }
        }
    }
};
// @lc code=end

/*

测试用例：
[[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]

[[1,2],[3,4]]

21/21 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.1 MB)

每次旋转四个点，多次绕圈，难点就是烦人的坐标转换...
*/