/*
题目描述
地上有一个m行和n列的方格。
一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
  但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/
class Solution {
public:
    int movingCount(int threshold, int rows, int cols){
        if(rows <= 0 || cols <= 0 || threshold < 0)  return 0;
        bool *visited = new bool[rows*cols];
        for(int i=0;i<rows*cols;i++)    visited[i]=false;
        int count = 0;
        
        move(threshold,rows,cols,0,0,visited,count);
        return count;
    }
    
    void move(int threshold, int rows, int cols, int x, int y, bool* visited, int &count){
        //!check(threshold,x,y) 如果此点不可行，后面的通路要被阻断
        if(x < 0 || x >= rows || y < 0 || y>= cols || visited[x*cols+y] || !check(threshold,x,y))    return;
        cout <<'('<<x<<','<<y<<')'<< endl;
        if(visited[x*cols+y] == false){
            if(check(threshold,x,y))    count++;//防止循环访问
            visited[x*cols+y] = true;
            cout <<'('<<x<<','<<y<<')'<<"visited"<< endl;
        }
        move(threshold,rows,cols,x,y+1,visited,count);
        move(threshold,rows,cols,x+1,y,visited,count);
        move(threshold,rows,cols,x,y-1,visited,count);
        move(threshold,rows,cols,x-1,y,visited,count);
    }
    
    bool check(int threshold, int x, int y){
        int sum = 0;
        while(x)    sum += x%10, x /= 10;
        while(y)    sum += y%10, y /= 10;
        if(sum > threshold) return false;
        return true;
    }

    
};