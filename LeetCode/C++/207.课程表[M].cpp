/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode-cn.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (48.16%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    28.2K
 * Total Submissions: 56.8K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
 * 
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
 * 
 * 给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 2, [[1,0]] 
 * 输出: true
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
 * 
 * 示例 2:
 * 
 * 输入: 2, [[1,0],[0,1]]
 * 输出: false
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。详情请参见图的表示法。
 * 你可以假定输入的先决条件中没有重复的边。
 * 1 <= numCourses <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*int countDegree(vector<vector<int>> &M, int &numCourses){
        int ans = 0;
        for(auto i:M[numCourses])   if(i == 0)  ans++;
        return ans;
    }*/
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > adjacencyMatrix(numCourses+1, vector<int> (numCourses, 0));
        queue<int> zeroQueue;
        for(auto i : prerequisites){
            adjacencyMatrix[i[1]][i[0]] = 1;
            adjacencyMatrix[numCourses][i[0]]++;
        }
        //int inDegree = countDegree(adjacencyMatrix, numCourses);
        for(int i = 0; i < numCourses; i++){
            if(adjacencyMatrix[numCourses][i] == 0)
                  zeroQueue.push(i);
        }
        //cout << countDegree(adjacencyMatrix, numCourses) <<endl;
        while(!zeroQueue.empty()){
            int i = zeroQueue.front();
            zeroQueue.pop();
            for(int j = 0; j<numCourses; j++){
                if(adjacencyMatrix[i][j] == 1){
                    //adjacencyMatrix[i][j] = 0;
                    adjacencyMatrix[numCourses][j]--;
                    if(!adjacencyMatrix[numCourses][j]) zeroQueue.push(j);
                }
            }
            //cout << countDegree(adjacencyMatrix, numCourses) <<endl;
        }

        for(auto i: adjacencyMatrix[numCourses]){
            if(i > 0)   return false;
        }
        return true;

    }
};
// @lc code=end
/*使用邻接矩阵记录图的状态，但是为什么这么慢呢?
Accepted
46/46 cases passed (128 ms)
Your runtime beats 12.29 % of cpp submissions
Your memory usage beats 8.82 % of cpp submissions (81.4 MB)*/



/*此版本超时了，因为每次都要遍历n个列，查看入度，实际上已经出了的不需要再次查看了
Time Limit Exceeded
44/46 cases passed (N/A)
Testcase
2000
[[995,1232],[1232,719],[719,3],[3,656], ...]
class Solution {
public:
    int countDegree(vector<vector<int>> &M, int &numCourses){
        int ans = 0;
        for(auto i:M[numCourses])   if(i == 0)  ans++;
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > adjacencyMatrix(numCourses+1, vector<int> (numCourses, 0));
        for(auto i : prerequisites){
            adjacencyMatrix[i[1]][i[0]] = 1;
            adjacencyMatrix[numCourses][i[0]]++;
        }
        int inDegree = countDegree(adjacencyMatrix, numCourses);
        //cout << inDegree <<endl;
        while(inDegree < numCourses){
            for(int i = 0; i < numCourses;i++){
                if(adjacencyMatrix[numCourses][i] == 0){
                    for(int j = 0; j<numCourses; j++){
                        if(adjacencyMatrix[i][j] == 1){
                            adjacencyMatrix[i][j] = 0;
                            adjacencyMatrix[numCourses][j]--;
                        }
                    }
                }
            }
            int updateDegree = countDegree(adjacencyMatrix, numCourses);
            //cout << updateDegree <<endl;
            if(updateDegree == inDegree)    return false;
            inDegree = updateDegree;
        }
        for(auto i: adjacencyMatrix[numCourses]){
            if(i > 0)   return false;
        }
        return true;

    }
};
*/