/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 *
 * https://leetcode-cn.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (41.42%)
 * Likes:    57
 * Dislikes: 0
 * Total Accepted:    7.6K
 * Total Submissions: 17.8K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * 在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。
 * 
 * 每个矩形由其左下顶点和右上顶点坐标表示，如图所示。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: -3, 0, 3, 4, 0, -1, 9, 2
 * 输出: 45
 * 
 * 说明: 假设矩形面积不会超出 int 的范围。
 * 
 */

// @lc code=start
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long width, height;
        long long A1 = (C-A)*(D-B), A2 = (G-E)*(H-F);
        long long S = A1 + A2;
        //保持以靠左的矩形为参照物，故调整两者坐标
        if(A > E){
            int tmpA = E, tmpB = F, tmpC = G, tmpD = H;
            E = A, F = B, G = C, H = D;
            A = tmpA, B = tmpB, C = tmpC, D = tmpD;
        }
        if(F >= D || E >= C)    return S;
        else if(F > B){
            width = min(C - E, G - E);
            height = min(D - F, H - F);
        }
        else{
            if(H < B)   return S;
            else{
                width = min(C -E, G - E);
                height = min(H - B, D-B);
            }
        }
        return S-width*height;
    }
};
// @lc code=end

/*
3082/3082 cases passed (8 ms)
Your runtime beats 84.95 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (5.9 MB)
用long long 以免两个矩形面积太大在计算
long long A1 = (C-A)*(D-B), A2 = (G-E)*(H-F);
long long S = A1 + A2;
时溢出
*/