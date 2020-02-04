/*
题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 

习惯上我们把1当做是第一个丑数。

求按从小到大的顺序的第N个丑数。
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7)    return index;
        vector<int> ugly(index);
        ugly[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 1; i < index; i++){
            ugly[i] = min(2*ugly[p2], min(3*ugly[p3], 5*ugly[p5]));
            if(ugly[i] == 2*ugly[p2])    p2++;
            if(ugly[i] == 3*ugly[p3])    p3++;
            if(ugly[i] == 5*ugly[p5])    p5++;
            
        }
        return ugly[index - 1];
    }
};
















class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	if(index <= 0)	return -1;
    	vector<int> ugly(1,1);
    	int alpha[3] = {2,3,5};
    	bool flag = false;

    	int i, search, a, tmp, may;

    	for(i = 1; i < index; i++){
    		for(search = 0; search < ugly.size(); search++){
    			for(a = 0; a < 3; a++){
    				tmp = alpha[a] * ugly[i-1];
    				if(tmp > ugly[ugly.size()-1]){
    					if(flag){
    						may = tmp;
    						flag = true;
    					}
    					else if(tmp < may){
    						may = tmp;
                            break;
    					}
                        else{
                            break;
                        }
    				}
    			}
    			ugly.push_back(may);
    			flag = false;

    		}
    	}

    	return ugly[ugly.size()-1];
    }
};//内存爆了

