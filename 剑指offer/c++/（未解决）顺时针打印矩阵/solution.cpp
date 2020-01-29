/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 
1	2	3	4 
5	6	7	8 
9	10	11	12 
13	14	15	16 

则依次打印出数字

1 -> 2 -> 3 -> 4 -> 8 -> 12 -> 16 -> 15 -> 14 -> 13 -> 9 -> 5 -> 6 -> 7 -> 11 -> 10.*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
    	int up = 0, down = matrix.size()-1;
    	if(down == 0)	return matrix[0];
    	int left = 0, right = matrix[0].size()-1;//边界

    	int x = 0, y = 0;
    	std::vector<int> v;

    	while(left < right && up < down){
    		while(y < right){
    			v.push_back(matrix[x][y]);
    			y++;
    		}
    		v.push_back(matrix[x][y]);
    		x++;
    		up++;//已经完整输出一行

    		while(x < down){
    			v.push_back(matrix[x][y]);
    			x++;
    		}
    		v.push_back(matrix[x][y]);
    		y--;
    		right--;//已经完整输出一列

    		while(y > left){
    			v.push_back(matrix[x][y]);
    			y--;
    		}
    		v.push_back(matrix[x][y]);
    		x--;
    		down--;

    		while(x < up){
    			v.push_back(matrix[x][y]);
    			x--;
    		}
    		v.push_back(matrix[x][y]);
    		y++;
    		left--;
    	}
    	
    	return v;
    }
};



class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
    	int up = 0, down = matrix.size()-1;
    	if(down == 0)	return matrix[0];

    	int left = 0, right = matrix[0].size()-1;

    	std::vector<int> v;
    	int x = 0, y = 0;

    	while(left <= right && up <= down){
    		while(y <= right){
    			v.push_back(matrix[x][y]);
    			y++;
    		}
    		
    		up++;

    		while(x <= down){
    			v.push_back(matrix[x][y]);
    			x++;
    		}
    		
    		down--;

    		while(y >= left){
    			v.push_back(matrix[x][y]);
    			y--;
    		}
    		
    		right++;

    		while(x <= up){
    			v.push_back(matrix[x][y]);
    			x--;
    		}
    		
    		left++;
    	}
    	return v;
    }
};