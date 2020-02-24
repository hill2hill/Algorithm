/*
题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。

不能使用除法。
（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）
*/
//O(N) 有重复的部分就应该有办法累积进行存储
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int s = A.size();
        vector<int> B(s,1);
        for(int i = 1; i<s; i++){
            B[i] = B[i-1] * A[i-1];
        }
        int tmp = A[s-1];
        for(int j = s-2; j>=0; j--){
            B[j] *= tmp;
            tmp *= A[j];
        }

        return B;
    }
};