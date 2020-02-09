/*
题目描述
统计一个数字在排序数组中出现的次数。
*/
//思路：两次二分查找
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
    	int len = data.size();
        if(len == 0)	return 0;
        if(k < data[0] || k > data[len - 1])	return 0;
        int tmp_left, tmp_right, leftIndex, rightIndex;

        tmp_left = 0, tmp_right = len -1;
        while(tmp_left <= tmp_right){
        	int mid = (tmp_left+tmp_right)/2;
        	if(data[mid] == k && ((data[mid - 1] != k) || (mid == 0))){
        		leftIndex = mid;
        		break;
        	}
        	else if(data[mid] >= k){
        		tmp_right = mid - 1;
        	}
        	else{
        		tmp_left = mid + 1;
        	}
        }
        if(tmp_left > tmp_right)	return 0;

        tmp_left = 0, tmp_right = len -1;
        while(tmp_left <= tmp_right){
        	int mid = (tmp_left+tmp_right)/2;
        	if(data[mid] == k && ((data[mid + 1] != k) || (mid == len - 1))){
        		rightIndex = mid;
        		break;
        	}
        	else if(data[mid] <= k){
        		tmp_left = mid + 1;
        	}
        	else{
        		tmp_right = mid - 1;
        	}
        }

        return rightIndex - leftIndex + 1;
    }
};