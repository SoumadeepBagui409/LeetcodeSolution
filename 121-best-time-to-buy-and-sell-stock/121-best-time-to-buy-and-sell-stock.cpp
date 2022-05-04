class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> prefPrice(prices.size(),0);
        prefPrice[prices.size()-1] = prices[prices.size()-1];
        for(int j = prices.size()-2;j>=0;j--){
            prefPrice[j] = max(prefPrice[j+1],prices[j]);
        }
        int ans = 0;
        for(int i = 0;i<prices.size()-1;i++){
            ans = max(ans,prefPrice[i+1]-prices[i]);
        }
        return ans;
    }
};