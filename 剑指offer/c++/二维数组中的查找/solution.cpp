class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size() == 0 || array[0].size() == 0)    return false;
        
        int rows = array.size();
        int cols = array[0].size();
        cout << rows << ' ' << cols << endl;
        for(int row = 0, col = cols-1; row < rows && col >= 0;){
            if(array[row][col] > target){
                col--;
            }
            else if(array[row][col] < target){
                row++;
            }
            else if(array[row][col] == target){
                return true;
            }
        }
        return false;
    }
};