class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        stack<int> st;
        int sz = pushed.size();
        while(i < sz){
            st.push(pushed[i]);
            i++;
            while(!st.empty() && popped[j] == st.top()){
                j++;
                st.pop();
            }
        }
        return st.empty();
        
    }
};