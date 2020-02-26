/*
题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
例如

a b c e
s f c s
a d e e
​	
矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，

因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/
//又一个回溯~
#include <iostream>
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str){
    	bool* visited = new bool[rows*cols];
    	for(int i = 0; i < rows*cols; i++){
    		visited[i] = false;
    	}
    	for(int i = 0; i < rows*cols; i++){
    		if(matrix[i] == str[0]){
            cout << "Go in from "<<matrix[i]<<"("<<i/cols<<","<<i%cols<<"):"<<endl;
    			if(check(matrix,rows,cols,str,i/cols,i%cols,visited))		return true;
    		}
    	}
    	return false;
    }

    bool check(char* matrix, int rows, int cols, char* str, int x, int y, bool* visited){
    
    	if(*str == '\0')	return true;
    	if(*matrix == '\0' || x<0 || y<0 || x>=rows || y>=cols || visited[x*cols+y])	return false;
      cout << ""<<matrix[x*cols+y]<<"("<<x<<","<<y<<"):?";
    	
    if(matrix[x*cols+y] == *str){
        cout <<matrix[x*cols+y]<<" checking..."<<endl;
        visited[x*cols+y] = true;
        str++;
        if(check(matrix,rows,cols,str,x+1,y,visited)
            || check(matrix,rows,cols,str,x,y+1,visited)
            || check(matrix,rows,cols,str,x-1,y,visited)
            || check(matrix,rows,cols,str,x,y-1,visited))   return true;
        else {
            cout <<matrix[x*cols+y]<<" failed half way..."<<endl;
            str--;
            visited[x*rows+y] = false;
            return false;
        }
    }
    else{
        cout <<matrix[x*cols+y]<<" dont match"<<endl;
    }
    	
    	return false;
    }

};
int main() {
    Solution s;
    bool res = false;
    char* matrix = "ABCESFCSADEE", *str = "SEE";
    res = s.hasPath(matrix,3,4,str);
    std::cout << "Hello World!\n";
    if(res) cout <<"TRUE";
    else cout <<"FALSE";
}