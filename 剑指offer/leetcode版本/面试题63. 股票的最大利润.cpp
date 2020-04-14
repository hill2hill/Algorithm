class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)  return 0;
        int min = prices[0];
        int ans = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > min){
                ans = max(ans, prices[i] - min);
            }
            else if(prices[i] < min){
                min = prices[i];
            }
        }
        return ans;
    }
};