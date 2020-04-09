class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int sz = nums.size();
        vector<int> mp(sz,0);
        //unordered_map<int,int> mp;
        for(auto i : nums){
            if(mp[i]){
                return i;
            }
            else{
                mp[i] = 1;
            }
        }
        
        
        return 0;
    }
};

/*
执行用时 :84 ms, 在所有 C++ 提交中击败了39.59%的用户
内存消耗 :23.8 MB, 在所有 C++ 提交中击败了100.00%的用户
*/