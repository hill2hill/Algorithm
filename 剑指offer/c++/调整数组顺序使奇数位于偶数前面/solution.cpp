/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得
所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变
*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size() == 0)	return;
        int length = array.size();
        bool flag = true;
        while(flag){
        	flag = false;
        	for(int i = 0;i < length - 1;i++){
        		if(array[i+1] & 1 && !(array[i] & 1)){
        			array[i] += array[i+1];
        			array[i+1] = array[i] - array[i+1];
        			array[i] -= array[i+1];
        			flag = true;
        		}
        	}
        }
    }
};//冒泡排序思路，用快排应该更快！
        	
        	