/*
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如
	输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。

	由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。

	如果不存在则输出0。
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	int len = numbers.size();
    	if(len == 0)	return 0;
    	if(len == 1)	return numbers[0];
    	int flag = 0, maybe;
    	for(int i = 0; i < len; i++){
    		if(flag == 0){
    			maybe = numbers[i];
    			flag++;
    		}
    		else{
    			if(numbers[i] == maybe){
    				flag++;
    			}
    			else{
    				flag--;
    			}
    		}
    	}
    	if(flag){
            flag = 0;
            for(int i = 0; i < len; i++){
                if(maybe == numbers[i]){
                    flag++;
                }
            }
            if(flag>len/2)    return maybe;
        };
    	return 0;
    }
};