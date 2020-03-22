/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (39.39%)
 * Likes:    344
 * Dislikes: 0
 * Total Accepted:    45K
 * Total Submissions: 109.8K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution {
private:
	int word_len;
	int row, col;
	string word;
	vector<vector<char>> board;
	vector<vector<bool>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        if(row == 0)	return false;
        col = board[0].size();
        if(col == 0)	return false;
        this -> word = word;
        word_len = word.length();
        //if(row == 1 && col == 1 && word_len == 1 && word[0] == board[0][0]) return true;
        this -> visited = vector<vector<bool>> (row, vector<bool> (col, false));
        this -> board = board;
        for(int i = 0; i<row; i++){
        	for(int j = 0; j<col; j++){
        		if(search(i,j,0)) return true;
        	}
        }
        return false;
    }
    bool search(int x, int y, int index){
        if(board[x][y] != word[index])	return false;
    	if(index == word_len-1 && board[x][y] == word[index])	return true;
    	
    	visited[x][y] = true;
    	if(x > 0 && !visited[x-1][y] && search(x-1, y, index+1)) return true;
    	
    	if(x < row-1 && !visited[x+1][y] && search(x+1, y, index+1)) return true;

		if(y > 0 && !visited[x][y-1] && search(x, y-1, index+1)) return true;

		if(y < col-1 && !visited[x][y+1] && search(x, y+1, index+1)) return true;

    	visited[x][y] = false;
    	return false;
    }
};
// @lc code=end

/*
DSF搜索，用visited记录是否已经被访问
无法向四方延伸的情况，要注意，不能向外扩张：
应使用if(index == word_len-1 && board[x][y] == word[index])
而非if(index == word_len）
[["a"]]\n"a"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABXCED"
89/89 cases passed (28 ms)
Your runtime beats 75.35 % of cpp submissions
Your memory usage beats 49.49 % of cpp submissions (11.3 MB)
*/