/*
题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。

不能使用除法。
（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）
*/
//O(N^2) 只读一次A
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	int s = A.size();
    	vector<int> B(s,1);
    	if(A.size()==0)	return B;

    	for(int i = 0; i < s; i++){
    		for(int j = 0; j < s; j++){
    			if(i == j){
    				continue;
    			}
    			else{
    				B[j] *= A[i];
    			}
    		}
    	}

    	return B;
    }
};